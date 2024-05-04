import serial
import time
import random

# Establish connection to Arduino
ser = serial.Serial('/dev/tty.usbmodem21101', 19200)

try:
    while True:
        # Generate a random value between 0 and 100
        value = random.randint(0, 10)
        
        # Send this value to the Arduino
        ser.write(f"{value}\n".encode())

        # Print the value for debugging purposes
        print(f"Sent value: {value}")
        
        # Wait a bit before sending the next value to simulate a more realistic scenario
        time.sleep(1)
except KeyboardInterrupt:
    print("Program terminated.")
finally:
    ser.close()

# try:
#     while True:
#         # Generate a value between 0 and 100 (this is just a placeholder)
#         value = int(input("Enter a value between 0 and 100: "))
        
#         # Send this value to the Arduino
#         ser.write(f"{value}\n".encode())
        
#         # Wait a bit before sending the next value
#         time.sleep(0.1)
# except KeyboardInterrupt:
#     print("Program terminated.")
# finally:
#     ser.close()
