# Scara_Robot
5EE project. this project contains the code and explanation of my scara robot.<br />
<br />
# Examples
In the file section you will find some examples of code.<br />
"How_To_Use_Library": file on how to perform only homing with arduino code, can be used as a template.<br />
"Pick_up_simulation": file with example where the robot does a homing then does a simulation of how it would pick up a cube, then puts it right and then goes back to zero position. Please note this code is without the gripper attached.<br />
<br />
# library
I wrote a library for determining the zero position, which you can download as a (.zip) file. Determining the zero position should always be done before starting a programme. Attention: the programme does not ensure that while running the programme in the (void loop) the motors are limited keep in mind that you do not turn too far to the left or right.<br />
<br />
In the examples is their a file "How_To_Use_Library" with a example code for how to use the library.<br />   
<br />   
The library will also define the pins for you so you did not have to do that.
How to use:<br />

  sketch - include library - add .ZIP library - select the zip file<br />
  #include<homing.h><br />
  homing myHoming;<br />
  void setup() {<br />
  myHoming.setup();<br />
}<br />
# pinout
