#ifndef Home_h
#define Home_h

#include <AccelStepper.h>

class Home {
public:
  // Pin Definitions
  static const int enPin = 8;
  static const int stepper1_step = 2;
  static const int stepper1_dir = 5;
  static const int stepper2_step = 3;
  static const int stepper2_dir = 6;
  static const int stepper3_step = 4;
  static const int stepper3_dir = 7;
  static const int stepper4_step = 12;
  static const int stepper4_dir = 13;
  static const int limit1 = 14;
  static const int limit2 = 15;
  static const int limit3 = 16;
  static const int limit4 = 17;
  static const int home = 500;

  // Constructor
  Home();

  // Public methods
  void setup();
  void homing();
  void touchingswitch();

private:
  AccelStepper stepper1;
  AccelStepper stepper2;
  AccelStepper stepper3;
  AccelStepper stepper4;
};

#endif