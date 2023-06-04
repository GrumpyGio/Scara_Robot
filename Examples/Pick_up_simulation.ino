#include <AccelStepper.h>

const int enPin = 8;

byte good = 0;
// Define stepper pins
#define stepper1_step 2
#define stepper1_dir 5
#define stepper2_step 3
#define stepper2_dir 6
#define stepper3_step 4
#define stepper3_dir 7
#define stepper4_step 12
#define stepper4_dir 13

int mark1 = 500;
int mark2 = -500;
int mark3 = 0;
int mark4 = 0;
int mark5 = 0;
int mark6 = 0;

// Define stepper stepper objects
AccelStepper stepper1(1, stepper1_step, stepper1_dir);
AccelStepper stepper2(1, stepper2_step, stepper2_dir);
AccelStepper stepper3(1, stepper3_step, stepper3_dir);
AccelStepper stepper4(1, stepper4_step, stepper4_dir);

// Define limit switch pins
#define limit1 14
#define limit2 15
#define limit3 16
#define limit4 17

#define home 500


void setup() {

  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);
  Serial.begin(9600);
  // Set limit switch pins as input
  pinMode(limit1, INPUT_PULLUP);
  pinMode(limit2, INPUT_PULLUP);
  pinMode(limit3, INPUT_PULLUP);
  pinMode(limit4, INPUT_PULLUP);

  // Set stepper1 to stepper4 speed and acceleration
  stepper1.setMaxSpeed(200);
  stepper1.setAcceleration(100);
  stepper2.setMaxSpeed(1200);
  stepper2.setAcceleration(850);
  stepper3.setMaxSpeed(1200);
  stepper3.setAcceleration(850);
  stepper4.setMaxSpeed(1200);
  stepper4.setAcceleration(850);
  homing();
  Serial.println("setup");
}

void loop() {

  stepper2.moveTo(500);
  stepper3.moveTo(450);
  stepper4.moveTo(500);
  while (stepper2.currentPosition() != 500) {
    stepper2.run();
    stepper3.run();
    stepper4.run();
  }
  stepper1.moveTo(-2000);
  while (stepper1.currentPosition() != -2000) {
    stepper1.run();
  }
  delay(1500);
  stepper1.moveTo(0);
  while (stepper1.currentPosition() != 0) {
    stepper1.run();
  }
  delay(1000);
  stepper2.moveTo(-500);
  stepper3.moveTo(-450);
  stepper4.moveTo(-500);
  while (stepper2.currentPosition() != -500) {
    stepper2.run();
    stepper3.run();
    stepper4.run();
  }
  delay(1500);
  stepper1.moveTo(-2000);
  while (stepper1.currentPosition() != -2000) {
    stepper1.run();
  }
  delay(1500);
  stepper1.moveTo(0);
  while (stepper1.currentPosition() != 0) {
    stepper1.run();
  }
  delay(2000);
  stepper2.moveTo(0);
  stepper3.moveTo(0);
  stepper4.moveTo(0);
  while (stepper2.currentPosition() != 0) {
    stepper2.run();
    stepper3.run();
    stepper4.run();
  }
  delay(500000);
}
void homing() {
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
  while (stepper1.currentPosition() != -2520) {
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
  delay(1500);
  return;
}
void touchingswitch() {
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
  return;
}