# CURRENT WORKING VISUALIZER 5-1-23
# pip uninstall pygame
# pip install pygame --pre


import argparse
from src.stream_analyzer import Stream_Analyzer
import time

# Arduino connection
import serial
import time
import random

arduino = serial.Serial('/dev/cu.usbmodem1301', 19200)
time.sleep(0) # Wait for the connection to initialize

def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('--device', type=int, default=None, dest='device',
                        help='pyaudio (portaudio) device index')
    parser.add_argument('--height', type=int, default=450, dest='height',
                        help='height, in pixels, of the visualizer window')
    parser.add_argument('--n_frequency_bins', type=int, default=400, dest='frequency_bins',
                        help='The FFT features are grouped in bins')
    parser.add_argument('--verbose', action='store_true')
    parser.add_argument('--window_ratio', default='24/9', dest='window_ratio',
                        help='float ratio of the visualizer window. e.g. 24/9')
    parser.add_argument('--sleep_between_frames', dest='sleep_between_frames', action='store_true',
                        help='when true process sleeps between frames to reduce CPU usage (recommended for low update rates)')
    return parser.parse_args()

def convert_window_ratio(window_ratio):
    if '/' in window_ratio:
        dividend, divisor = window_ratio.split('/')
        try:
            float_ratio = float(dividend) / float(divisor)
        except:
            raise ValueError('window_ratio should be in the format: float/float')
        return float_ratio
    raise ValueError('window_ratio should be in the format: float/float')

def map_frequencies(frequencies, old_min, old_max, new_min, new_max):
    # Map each frequency value from the old range to the new range
    mapped_frequencies = [
        new_min + (new_max - new_min) * (freq - old_min) / (old_max - old_min)
        for freq in frequencies
    ]

    # Convert mapped frequencies to integers that don't exceed 180
    mapped_frequencies = [min(new_max, int(round(f))) for f in mapped_frequencies]

    # return the average of all the values in mapped_frequencies
    # average = sum(mapped_frequencies) / len(mapped_frequencies)
    # print("value is", average)
    # return int(average)

    # Convert the list of integers to a comma-separated string and add a newline at the end
    result_string = ','.join(map(str, mapped_frequencies)) + '\n'
    # print("result_string is: ", result_string)
    return result_string

def send_command(command):
    arduino.write(f"{command}\n".encode())
    # time.sleep(2)  # Wait for Arduino to process the command

def run_FFT_analyzer():
    args = parse_args()
    window_ratio = convert_window_ratio(args.window_ratio)

    ear = Stream_Analyzer(
                    device = args.device,        # Pyaudio (portaudio) device index, defaults to first mic input
                    rate   = None,               # Audio samplerate, None uses the default source settings
                    FFT_window_size_ms  = 60,    # Window size used for the FFT transform
                    updates_per_second  = 500,   # How often to read the audio stream for new data
                    smoothing_length_ms = 50,    # Apply some temporal smoothing to reduce noisy features
                    n_frequency_bins = args.frequency_bins, # The FFT features are grouped in bins
                    visualize = 0,               # Visualize the FFT features with PyGame
                    verbose   = args.verbose,    # Print running statistics (latency, fps, ...)
                    height    = args.height,     # Height, in pixels, of the visualizer window,
                    window_ratio = window_ratio  # Float ratio of the visualizer window. e.g. 24/9
                    )

    fps = 30  #How often to update the FFT features + display
    last_update = time.time()
    print("All ready, starting audio measurements now...")
    fft_samples = 0
    # 16 + 6
    # values_at_frequencies_of_interest = [
    #     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    # ]
    # 22
    values_at_frequencies_of_interest = [
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
    # 23
    # values_at_frequencies_of_interest = [
    #     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    #     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
    # 24
    # values_at_frequencies_of_interest = [
    #     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    #     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
    # values_at_frequencies_of_interest = [
    #     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    #     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    #     0, 0, 0, 0
    # ]
    # [50, 1300, 1950, 3250, 3900, 4550]
    while True:
        if (time.time() - last_update) > (1./fps):
            last_update = time.time()
            raw_fftx, raw_fft, binned_fftx, binned_fft, values_at_frequencies_of_interest = ear.get_audio_features()
            print("Values at this time are:", values_at_frequencies_of_interest)
            fft_samples += 1
            #if fft_samples % 20 == 0:
            #    print(f"Got fft_features #{fft_samples} of shape {raw_fft.shape}")

            mapped_frequencies = map_frequencies(values_at_frequencies_of_interest, 0, 10, 0, 10)
            print("Relative Values are: ", mapped_frequencies)
            send_command(mapped_frequencies)
    
        elif args.sleep_between_frames:
            time.sleep(((1./fps)-(time.time()-last_update)) * 0.99)

if __name__ == '__main__':
    run_FFT_analyzer()
