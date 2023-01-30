#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
// Declarando los servos
Adafruit_PWMServoDriver placaPCA = Adafruit_PWMServoDriver(0x40);

// Posición inicial de los motores
unsigned int angle_x = 350;
unsigned int angle_y = 350;
unsigned int angle_cell = 350;

int joystick_cell = 32;
int joystick_x = 34;
int joystick_y = 35;


void setup() {
  Serial.begin(115200);

  placaPCA.begin();
  placaPCA.setPWMFreq(60);
  placaPCA.setPWM(0, 0, angle_x);
  placaPCA.setPWM(1, 0, angle_y);
  placaPCA.setPWM(2, 0, angle_cell);
}

void loop() {
  while (analogRead(joystick_x) == 4095 && angle_x < 575) {
    angle_x ++;
    placaPCA.setPWM(0, 0, angle_x);
    delay(5);
  }

  while (analogRead(joystick_x) == 0 && angle_x > 125) {
    angle_x--;
    placaPCA.setPWM(0, 0, angle_x);
    delay(5);
  }

    while (analogRead(joystick_y) == 4095 && angle_y < 575) {
    angle_y++;
    placaPCA.setPWM(1, 0, angle_y);
    delay(5);
  }

  while (analogRead(joystick_y) == 0 && angle_y > 125) {
    angle_y--;
    placaPCA.setPWM(1, 0, angle_y);
    delay(5);
  }

    while (analogRead(joystick_cell) == 4095 && angle_cell < 575) {
    angle_cell ++;
    placaPCA.setPWM(2, 0, angle_cell);
    delay(5);
  }

    while (analogRead(joystick_cell) == 0 && angle_cell > 125) {
    angle_cell --;
    placaPCA.setPWM(2, 0, angle_cell);
    delay(5);
  }
}
