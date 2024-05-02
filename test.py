import numpy as np
import pyaudio

def stream_audio_frequencies(frequencies):
    # Audio configuration parameters
    FORMAT = pyaudio.paInt16
    CHANNELS = 1
    RATE = 44100
    CHUNK = 1024  # Number of audio samples per frame

    # Initialize PyAudio
    audio = pyaudio.PyAudio()

    # Open stream
    stream = audio.open(format=FORMAT, channels=CHANNELS,
                        rate=RATE, input=True,
                        frames_per_buffer=CHUNK)

    try:
        print("Streaming started...")
        while True:
            data = stream.read(CHUNK)
            # Convert stream data to numpy array
            samples = np.frombuffer(data, dtype=np.int16)

            # Apply FFT and get frequency spectrum
            fft_result = np.fft.fft(samples)
            fft_freq = np.fft.fftfreq(len(samples), 1/RATE)

            # Extract amplitude for specific frequencies
            amplitudes = {}
            for freq in frequencies:
                # Find the closest index in fft_freq that matches the frequency
                index = np.argmin(np.abs(fft_freq - freq))
                amplitudes[freq] = np.abs(fft_result[index])

            print(amplitudes)

    except KeyboardInterrupt:
        print("Streaming stopped.")

    finally:
        stream.stop_stream()
        stream.close()
        audio.terminate()

# Frequencies to monitor
frequencies = [50, 1300, 1950, 3250, 3900, 4550]
stream_audio_frequencies(frequencies)
