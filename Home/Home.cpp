#include "Home.h"

Home::Home()
  : stepper1(1, stepper1_step, stepper1_dir),
    stepper2(1, stepper2_step, stepper2_dir),
    stepper3(1, stepper3_step, stepper3_dir),
    stepper4(1, stepper4_step, stepper4_dir) {
}

void Home::setup() {
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);
  Serial.begin(9600);
  
  // Set limit switch pins as input
  pinMode(limit1, INPUT_PULLUP);
  pinMode(limit2, INPUT_PULLUP);
  pinMode(limit3, INPUT_PULLUP);
  pinMode(limit4, INPUT_PULLUP);

  // Set stepper1 to stepper4 speed and acceleration
  stepper1.setMaxSpeed(400);
  stepper1.setAcceleration(200);
  stepper2.setMaxSpeed(400);
  stepper2.setAcceleration(200);
  stepper3.setMaxSpeed(400);
  stepper3.setAcceleration(200);
  stepper4.setMaxSpeed(400);
  stepper4.setAcceleration(200);

  homing();
}

void Home::homing() {
  touchingswitch();
  Serial.println("done homing");
  stepper1.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);
  stepper3.setCurrentPosition(0);
  stepper4.setCurrentPosition(0);
  delay(2000);
  Serial.println("o");
  stepper1.moveTo(-2520);
  stepper2.moveTo(-2000);
  stepper3.moveTo(-1500);
  stepper4.moveTo(390);
  while (stepper1.currentPosition() != home) {
    stepper1.run();
    stepper2.run();
    stepper3.run();
    stepper4.run();
  }
  Serial.println("moved");
  delay(500);
  stepper1.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);
  stepper3.setCurrentPosition(0);
  stepper4.setCurrentPosition(0);
}

void Home::touchingswitch() {
  // Rotate motor1 until it hits the limit switch
  while (digitalRead(limit1) == HIGH) {
    stepper1.setSpeed(200);  // Set motor1 speed
    stepper1.runSpeed();     // Rotate motor1
  }
  stepper1.stop();  // Stop motor1 when it hits the limit switch

  // Rotate motor2 until it hits the limit switch
  while (digitalRead(limit2) == HIGH) {
    stepper2.setSpeed(200);  // Set motor2 speed
    stepper2.runSpeed();     // Rotate motor2
  }
  stepper2.stop();  // Stop motor2 when it hits the limit switch

  // Rotate motor3 until it hits the limit switch
  while (digitalRead(limit3) == HIGH) {
    stepper3.setSpeed(200);  // Set motor3 speed
    stepper3.runSpeed();     // Rotate motor3
  }
  stepper3.stop();  // Stop motor3 when it hits the limit switch

  // Rotate motor4 until it hits the limit switch
  while (digitalRead(limit4) == HIGH) {
    stepper4.setSpeed(-200);  // Set motor4 speed
    stepper4.runSpeed();      // Rotate motor4
  }
  stepper4.stop();  // Stop motor4 when it hits the limit switch
}