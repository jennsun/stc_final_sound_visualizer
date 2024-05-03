import serial
import time
import random

arduino = serial.Serial('/dev/cu.usbmodem21101', 19200)
time.sleep(0) # Wait for the connection to initialize

def send_command(command):
    arduino.write(f"{command}\n".encode())
    time.sleep(2)  # Wait for Arduino to process the command

# ############# Basic example of human input telling it to turn to 0 or 180 degrees
# while True:
#     # Example: Sending commands based on user input
#     command = input("Enter 1 to turn on the servo, 0 to turn it off: ")
#     if command in ['0', '1']:
#         send_command(command)
#     else:
#         print("Invalid command")

############ Go from 0 to 1 inputs
index = 0
while True:
    # # Example: Sending commands based on user input
    if index % 2 == 0:
        command = '180'
    else:
        command = '30'
    print("command is ", command)
    send_command(command)
    index += 1

    # Send command that is typed in by the user through terminal
    # command = input("Enter the angle to turn the servo to (0-180): ")
    # if command.isdigit() and 0 <= int(command) <= 180:
    #     send_command(command)
    # else:
    #     print("Invalid command")

# Randomly generate values from 0 to 10 and map that to an angle the servo should turn
while True:
    # Example: Sending commands based on random values
    value = random.randint(0, 10)  # Randomly generate a number from 0 to 10
    # Map value to the range between 0 and 180
    angle = int(value * (180/10))
    print("angle is ", angle)
    send_command(angle)
    # time.sleep(3)  # Wait 3 seconds before the next angle

arduino.close()  # Close the serial connection