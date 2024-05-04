#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

#define SERVOMIN  0
#define SERVOMAX  4096
#define SERVO_FREQ 50

void setup() {
  Serial.begin(19200);
  // Serial.begin(38400);
  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);

  pwm2.begin();
  pwm2.setPWMFreq(SERVO_FREQ);
  delay(2000);

  // randomSeed(analogRead(0));

  // Set motors to 0
  for (int i = 0; i <= 15; i++) {
    pwm.setPin(0, 0, false);
    pwm2.setPin(0, 0, false);
  }
}

// void loop() {
//   String input = "0,2,0,2,0,0,1,1,1,2,1,2";
//   // uint16_t command = input.toInt();
//   // input.trim();  // Trim any whitespace or new lines

//   // // Split the string based on commas
//   // uint16_t servos[26];  // Assuming there are up to 6 values
//   int servos[12];
//   int index = 0;
//   int lastIndex = 0;
//   int servosIndex = 0;

//   while ((index = input.indexOf(',', lastIndex)) != -1) {
//     Serial.println("ServosIndex");
//     Serial.println(servosIndex);
//     Serial.println("Substring");
//     Serial.println(input.substring(lastIndex, index).toInt());
//     servos[servosIndex++] = input.substring(lastIndex, index).toInt();
//     lastIndex = index + 1;
//   }

//   // Get the last element
//   servos[servosIndex] = input.substring(lastIndex).toInt();

//   // // // Apply to servos
//   // // for (uint16_t i = 0; i <= servosIndex; i++) {
//   // //   uuint16_t16_t pulselen = map(servos[i], 0, 100, SERVOMIN, SERVOMAX);
//   // //   pwm.setPin(i, pulselen, false);  // Apply to servo on pin i
//   // // }

//   // uint16_t lengths[26];
//   int len1 = map(servos[0], 0, 100, SERVOMIN, SERVOMAX);
//   int len2 = map(servos[1], 0, 100, SERVOMIN, SERVOMAX);
//   int len3 = map(servos[2], 0, 100, SERVOMIN, SERVOMAX);
//   int len4 = map(servos[3], 0, 100, SERVOMIN, SERVOMAX);
//   int len5 = map(servos[4], 0, 100, SERVOMIN, SERVOMAX);
//   int len6 = map(servos[5], 0, 100, SERVOMIN, SERVOMAX);
//   int len7 = map(servos[6], 0, 100, SERVOMIN, SERVOMAX);
//   int len8 = map(servos[7], 0, 100, SERVOMIN, SERVOMAX);
//   int len9 = map(servos[8], 0, 100, SERVOMIN, SERVOMAX);
//   int len10 = map(servos[9], 0, 100, SERVOMIN, SERVOMAX);
//   int len11 = map(servos[10], 0, 100, SERVOMIN, SERVOMAX);
//   int len12 = map(servos[11], 0, 100, SERVOMIN, SERVOMAX);
//   // int len13 = map(servos[12], 0, 100, SERVOMIN, SERVOMAX);
//   // int len14 = map(servos[13], 0, 100, SERVOMIN, SERVOMAX);
//   // int len15 = map(servos[14], 0, 100, SERVOMIN, SERVOMAX);
//   // uint16_t len16 = map(servos[15], 0, 100, SERVOMIN, SERVOMAX);
//   // uint16_t len17 = map(servos[16], 0, 100, SERVOMIN, SERVOMAX);
//   // uint16_t len18 = map(servos[17], 0, 100, SERVOMIN, SERVOMAX);
//   // uint16_t len19 = map(servos[18], 0, 100, SERVOMIN, SERVOMAX);
//   // uint16_t len20 = map(servos[19], 0, 100, SERVOMIN, SERVOMAX);
//   // uint16_t len21 = map(servos[20], 0, 100, SERVOMIN, SERVOMAX);
//   // uint16_t len22 = map(servos[21], 0, 100, SERVOMIN, SERVOMAX);
//   // uint16_t len23 = map(servos[22], 0, 100, SERVOMIN, SERVOMAX);
//   // uint16_t len24 = map(servos[23], 0, 100, SERVOMIN, SERVOMAX);
//   // uint16_t len25 = map(servos[24], 0, 100, SERVOMIN, SERVOMAX);
//   // uint16_t len26 = map(servos[25], 0, 100, SERVOMIN, SERVOMAX);

//   for (int i = 0; i <= 11; i++) {
//     Serial.println("Length is");
//     Serial.println(map(servos[i], 0, 100, SERVOMIN, SERVOMAX));
//   }


//   // #############################
//   // Try to spin them the same amount
//   // uuint16_t16_t pulselen = map(command, 0, 100, SERVOMIN, SERVOMAX);
//   // pwm.setPin(0, pulselen, false);
//   // pwm.setPin(1, pulselen, false);
//   // pwm.setPin(2, pulselen, false);
//   // pwm.setPin(3, pulselen, false);
//   // pwm.setPin(4, pulselen, false);
//   // pwm.setPin(5, pulselen, false);
//   // pwm.setPin(6, pulselen, false);
//   // pwm.setPin(7, pulselen, false);
//   // pwm.setPin(8, pulselen, false);
//   // pwm.setPin(9, pulselen, false);
//   // pwm.setPin(10, pulselen, false);
//   // pwm.setPin(11, pulselen, false);
//   // pwm.setPin(12, pulselen, false);
//   // pwm.setPin(13, pulselen, false);
//   // pwm.setPin(14, pulselen, false);
//   // pwm.setPin(15, pulselen, false);

//   // pwm2.setPin(0, pulselen, false);
//   // pwm2.setPin(1, pulselen, false);
//   // pwm2.setPin(2, pulselen, false);
//   // pwm2.setPin(3, pulselen, false);
//   // pwm2.setPin(4, pulselen, false);
//   // pwm2.setPin(5, pulselen, false);
//   // pwm2.setPin(6, pulselen, false);
//   // pwm2.setPin(7, pulselen, false);
//   // pwm2.setPin(8, pulselen, false);
//   // pwm2.setPin(9, pulselen, false);
//   // #############################


//   // Try to spin all of them differently #############################
//   // pwm.setPin(0, len1, false);
//   // pwm.setPin(1, len2, false);
//   // pwm.setPin(2, len3, false);
//   // pwm.setPin(3, len4, false);
//   // pwm.setPin(4, len5, false);
//   // pwm.setPin(5, len6, false);
//   // pwm.setPin(6, len7, false);
//   // pwm.setPin(7, len8, false);
//   // pwm.setPin(8, len9, false);
//   // pwm.setPin(9, len10, false);
//   // pwm.setPin(10, len11, false);
//   // pwm.setPin(11, len12, false);
//   // pwm.setPin(12, len13, false);
//   // pwm.setPin(13, len14, false);
//   // pwm.setPin(14, len15, false);
//   // pwm.setPin(15, len16, false);

//   // pwm2.setPin(0, len17, false);
//   // pwm2.setPin(1, len18, false);
//   // pwm2.setPin(2, len19, false);
//   // pwm2.setPin(3, len20, false);
//   // pwm2.setPin(4, len21, false);
//   // pwm2.setPin(5, len22, false);
//   // pwm2.setPin(6, len23, false);
//   // pwm2.setPin(7, len24, false);
//   // pwm2.setPin(8, len25, false);
//   // pwm2.setPin(9, len26, false);
//   // #############################

//   // Spinning 12 of them

//   pwm.setPin(0, len1, false);
//   pwm.setPin(1, len2, false);
//   pwm.setPin(2, len3, false);
//   pwm.setPin(3, len4, false);
//   pwm.setPin(4, len5, false);
//   pwm.setPin(5, len6, false);

//   pwm2.setPin(0, len7, false);
//   pwm2.setPin(1, len8, false);
//   pwm2.setPin(2, len9, false);
//   pwm2.setPin(3, len10, false);
//   pwm2.setPin(4, len11, false);
//   pwm2.setPin(5, len12, false);

//   // uint16_t pos = input.touint16_t();
//   // uuint16_t16_t pulselen = map(pos, 0, 100, SERVOMIN, SERVOMAX);
//   // // uuint16_t16_t pulselen2 = map(pos, 100, 0, SERVOMAX, SERVOMIN);
//   // Serial.pruint16_tln("Pulse Length 1 is");
//   // Serial.pruint16_tln(pulselen);
//   // // Serial.pruint16_tln("Pulse Length 2 is");
//   // // Serial.pruint16_tln(pulselen2);
//   // pwm.setPin(0, pulselen, false);  // servo is connected to pin 0
//   // pwm2.setPin(0, pulselen, false);  // servo is connected to pin 0
// }

// void loop() {
//   Serial.println("Hi");
// }

void loop() {
  // uint16_t pos = random(0, 11);  // Generates a random number between 0 and 10
  // uuint16_t16_t pulselen = map(pos, 0, 100, SERVOMIN, SERVOMAX);  // Adjust map range to 0-10
  // Serial.pruint16_t("Random Position: ");
  // Serial.pruint16_tln(pos);
  // Serial.pruint16_t("Pulse Length 1 is: ");
  // Serial.pruint16_tln(pulselen);
  
  // pwm.setPin(0, pulselen, false);  // Servo is connected to pin 0
  // pwm2.setPin(0, pulselen, false);  // Optionally control a second servo on pwm2
  
  // delay(1000);  // Adjust delay as needed for testing
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    // uint16_t command = input.toInt();
    // input.trim();  // Trim any whitespace or new lines

    // // Split the string based on commas
    // uint16_t servos[26];  // Assuming there are up to 6 values
    int servos[22];
    int index = 0;
    int lastIndex = 0;
    int servosIndex = 0;

    while ((index = input.indexOf(',', lastIndex)) != -1) {
      servos[servosIndex++] = input.substring(lastIndex, index).toInt();
      lastIndex = index + 1;
    }

    // Get the last element
    servos[servosIndex] = input.substring(lastIndex).toInt();

    // // // Apply to servos
    // // for (uint16_t i = 0; i <= servosIndex; i++) {
    // //   uuint16_t16_t pulselen = map(servos[i], 0, 100, SERVOMIN, SERVOMAX);
    // //   pwm.setPin(i, pulselen, false);  // Apply to servo on pin i
    // // }

    // uint16_t lengths[26];
    int maxint = 200;
    int len1 = map(servos[0], 0, maxint, SERVOMIN, SERVOMAX);
    int len2 = map(servos[1], 0, maxint, SERVOMIN, SERVOMAX);
    int len3 = map(servos[2], 0, maxint, SERVOMIN, SERVOMAX);
    int len4 = map(servos[3], 0, maxint, SERVOMIN, SERVOMAX);
    int len5 = map(servos[4], 0, maxint, SERVOMIN, SERVOMAX);
    int len6 = map(servos[5], 0, maxint, SERVOMIN, SERVOMAX);
    int len7 = map(servos[6], 0, maxint, SERVOMIN, SERVOMAX);
    int len8 = map(servos[7], 0, maxint, SERVOMIN, SERVOMAX);
    int len9 = map(servos[8], 0, maxint, SERVOMIN, SERVOMAX);
    int len10 = map(servos[9], 0, maxint, SERVOMIN, SERVOMAX);
    int len11 = map(servos[10], 0, maxint, SERVOMIN, SERVOMAX);
    int len12 = map(servos[11], 0, maxint, SERVOMIN, SERVOMAX);
    int len13 = map(servos[12], 0, maxint, SERVOMIN, SERVOMAX);
    int len14 = map(servos[13], 0, maxint, SERVOMIN, SERVOMAX);
    int len15 = map(servos[14], 0, maxint, SERVOMIN, SERVOMAX);
    int len16 = map(servos[15], 0, maxint, SERVOMIN, SERVOMAX);
    int len17 = map(servos[16], 0, maxint, SERVOMIN, SERVOMAX);
    int len18 = map(servos[17], 0, maxint, SERVOMIN, SERVOMAX);
    int len19 = map(servos[18], 0, maxint, SERVOMIN, SERVOMAX);
    int len20 = map(servos[19], 0, maxint, SERVOMIN, SERVOMAX);
    int len21 = map(servos[20], 0, maxint, SERVOMIN, SERVOMAX);
    int len22 = map(servos[21], 0, maxint, SERVOMIN, SERVOMAX);
    // int len23 = map(servos[22], 0, maxint, SERVOMIN, SERVOMAX);
    // int len24 = map(servos[23], 0, maxint, SERVOMIN, SERVOMAX);
    // int len25 = map(servos[24], 0, 300, SERVOMIN, SERVOMAX);
    // int len26 = map(servos[25], 0, 300, SERVOMIN, SERVOMAX);

    // #############################
    // Try to spin them the same amount
    // uuint16_t16_t pulselen = map(command, 0, 100, SERVOMIN, SERVOMAX);
    // pwm.setPin(0, pulselen, false);
    // pwm.setPin(1, pulselen, false);
    // pwm.setPin(2, pulselen, false);
    // pwm.setPin(3, pulselen, false);
    // pwm.setPin(4, pulselen, false);
    // pwm.setPin(5, pulselen, false);
    // pwm.setPin(6, pulselen, false);
    // pwm.setPin(7, pulselen, false);
    // pwm.setPin(8, pulselen, false);
    // pwm.setPin(9, pulselen, false);
    // pwm.setPin(10, pulselen, false);
    // pwm.setPin(11, pulselen, false);
    // pwm.setPin(12, pulselen, false);
    // pwm.setPin(13, pulselen, false);
    // pwm.setPin(14, pulselen, false);
    // pwm.setPin(15, pulselen, false);

    // pwm2.setPin(0, pulselen, false);
    // pwm2.setPin(1, pulselen, false);
    // pwm2.setPin(2, pulselen, false);
    // pwm2.setPin(3, pulselen, false);
    // pwm2.setPin(4, pulselen, false);
    // pwm2.setPin(5, pulselen, false);
    // pwm2.setPin(6, pulselen, false);
    // pwm2.setPin(7, pulselen, false);
    // pwm2.setPin(8, pulselen, false);
    // pwm2.setPin(9, pulselen, false);
    // #############################


    // Try to spin all of them differently #############################
    pwm.setPin(0, len1, false);
    pwm.setPin(1, len2, false);
    pwm.setPin(2, len3, false);
    pwm.setPin(3, len4, false);
    pwm.setPin(4, len5, false);
    pwm.setPin(5, len6, false);
    pwm.setPin(6, len7, false);
    pwm.setPin(7, len8, false);
    pwm.setPin(8, len9, false);
    pwm.setPin(9, len10, false);
    pwm.setPin(10, len11, false);
    pwm.setPin(11, len12, false);
    pwm.setPin(12, len13, false);
    pwm.setPin(13, len14, false);
    pwm.setPin(14, len15, false);
    pwm.setPin(15, len16, false);

    pwm2.setPin(0, len17, false);
    pwm2.setPin(1, len18, false);
    pwm2.setPin(2, len19, false);
    pwm2.setPin(3, len20, false);
    pwm2.setPin(4, len21, false);
    pwm2.setPin(5, len22, false);
    // pwm2.setPin(6, len23, false);
    // pwm2.setPin(7, len24, false);
    // pwm2.setPin(8, len25, false);
    // pwm2.setPin(9, len26, false);
    // #############################

    // Spinning 12 of them
  
    // pwm.setPin(0, len1, false);
    // pwm.setPin(1, len2, false);
    // pwm.setPin(2, len3, false);
    // pwm.setPin(3, len4, false);
    // pwm.setPin(4, len5, false);
    // pwm.setPin(5, len6, false);

    // pwm2.setPin(0, len7, false);
    // pwm2.setPin(1, len8, false);
    // pwm2.setPin(2, len9, false);
    // pwm2.setPin(3, len10, false);
    // pwm2.setPin(4, len11, false);
    // pwm2.setPin(5, len12, false);

    // uint16_t pos = input.touint16_t();
    // uuint16_t16_t pulselen = map(pos, 0, 100, SERVOMIN, SERVOMAX);
    // // uuint16_t16_t pulselen2 = map(pos, 100, 0, SERVOMAX, SERVOMIN);
    // Serial.pruint16_tln("Pulse Length 1 is");
    // Serial.pruint16_tln(pulselen);
    // // Serial.pruint16_tln("Pulse Length 2 is");
    // // Serial.pruint16_tln(pulselen2);
    // pwm.setPin(0, pulselen, false);  // servo is connected to pin 0
    // pwm2.setPin(0, pulselen, false);  // servo is connected to pin 0
  } else {
    Serial.println("Serial not received");
  }
}
