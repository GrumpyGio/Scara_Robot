# Scara_Robot
5EE project. this project contains the code and explanation of my scara robot.
# Examples
In the file section you will find some examples of code.
"How_To_Use_Library": file on how to perform only homing with arduino code, can be used as a template.
"Pick_up_simulation": file with example where the robot does a homing then does a simulation of how it would pick up a cube, then puts it right and then goes back to zero position. Please note this code is without the gripper attached.

# library
I wrote a library for determining the zero position, which you can download as a (.zip) file. Determining the zero position should always be done before starting a programme. Attention: the programme does not ensure that while running the programme in the (void loop) the motors are limited keep in mind that you do not turn too far to the left or right.
 
How to use:

sketch - include library - add .ZIP library - select the zip file
.#include<homing.h>
homing myHoming;
void setup() {
myHoming.setup();
}

# pinout
