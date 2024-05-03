// # Sending over an angle from 30 to 180 that corresponds to the servo motor's movement/position
// run using FFT_to_arduino.py

/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 8 servos, one after the other on the
  first 8 pins of the PCA9685

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815
  
  These drivers use I2C to communicate, 2 pins are required to  
  interface.

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  0 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  491.52 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  400 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// our servo # counter
uint8_t servonum = 0;
uint16_t last_known_angle = SERVOMIN; 
uint8_t initial_angle = SERVOMIN;
uint8_t new_angle = SERVOMAX;

void setup() {
  Serial.begin(9600);
  Serial.begin(19200);
  // Serial.println("8 channel Servo test!");

  // calculate SERVOMAX
  // 140, 640
  // int servomax = 4096 / [20 / 2.4];

  
  pwm.begin();
  pwm.reset();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  pwm2.begin();
  pwm2.reset();
  pwm2.setOscillatorFrequency(27000000);
  pwm2.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates


  // delay(10);
}

void loop() {
  uint16_t current_angle = SERVOMIN;
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    int command = input.toInt();
    Serial.print("Command received: ");
    Serial.println(command);
    current_angle = map(command, 0, 180, SERVOMIN, SERVOMAX);
    Serial.println("Current angle is");
    Serial.println(current_angle);
  } else {
    Serial.println("No new serial input; using last known angle.");
    current_angle = last_known_angle;
  }

  // Move to the last known or newly received angle
  // pwm.setPin(servonum, last_known_angle, false);
  if (current_angle > last_known_angle) {
    for (uint16_t pulselen = last_known_angle; pulselen < current_angle; pulselen++) {
      pwm.setPin(servonum, pulselen, false);
    }
  } else {
    for (uint16_t pulselen = last_known_angle; pulselen > current_angle; pulselen--) {
      pwm.setPin(servonum, pulselen, false);
    }
  }
  delay(20); // Short delay to allow the servo to move

  // servonum++;
  // if (servonum > 7) servonum = 0; // Reset servo counter after the 8th servo

  delay(2000); // Main loop delay to slow down the frequency of servo checks
}
