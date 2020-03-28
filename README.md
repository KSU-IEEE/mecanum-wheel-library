# mecanum-wheel-library
Library for using the mecanum wheels with the motor drivers

This the library that KSU's IEEE chapter uses for driving Mecanum wheels

# Installation
--------------------------------------------------------------------------------

Clone this repo directly into Arduino/lib/targets/libraries  
On some newer versions of Arduino you should clone it into Arduino/libraries

When installed, this library should look like:

Arduino/lib/targets/libraries/mecanum-wheel-library              		 (this library's folder)
Arduino/lib/targets/libraries/mecanum-wheel-library/mecanum_driver.cpp   (the library implementation files)
Arduino/lib/targets/libraries/mecanum-wheel-library/mecanum_driver.h 	 (the library description files)
Arduino/lib/targets/libraries/mecanum-wheel-library/readme.txt   		 (this file)

# Building
--------------------------------------------------------------------------------

After this library is installed, you just have to start the Arduino application.
You may see a few warning messages as it's built.

To use this library in a sketch, go to the Sketch | Import Library menu and
select Test.  This will add a corresponding line to the top of your sketch:
`include <mecanum_drive.h>`
To stop using this library, delete that line from your sketch.

Geeky information:
After a successful build of this library, a new file named "mecanum_drive.o" will appear
in "Arduino/lib/targets/libraries/mecanum_drive". This file is the built/compiled library
code.

# Using these classes  
--------------------------------------------------------------------------------
## The motor class  
instantiate by calling:  
`robot::motor myMotor = robot::motor(pinA, pinB, pwmPin);`  

the motor functions have to functions that you should worry about:
```c++  
myMotor.move_clockwise(int pwm);
myMotor.move_cclockwise(int pwm);
```  
Use these functions to move the motor clockwise and counter clockwise

## The robot_4_motor class  
This library is meant to be added to if we use robots that have more motors   
So this class specifically implenets movents for a robot with four motors.  
To instantiate it, call:  
`robot::robot_4_motor myAwesomeBot = robot::robot_4_motor(int array[12]);`  
The index of the array should represent that follow values:
|index|To Set|
|-----|--------------|
|0:|fRight.pinA|
|1:|fRight.pinB|
|2:|fRight.pwmPin|
|3:|fLeft.pinA|
|4:|fLeft.pinB|
|5:|fLeft.pwmPin|
|6:|bRight.pinA|
|7:|bRight.pinB|
|8:|bRight.pwmPin|
|9:|bLeft.pinA|
|10:|bLeft.pinB|
|11:|bLeft.pwmPin|  

The important functions for this robot are:  
```c++
myAwesomeBot.move_right(pwm);
myAwesomeBot.move_left(pwm);
myAwesomeBot.move_up(pwm);
myAwesomeBot.move_down(pwm)();
```  
The directions in this are in reguards to the robot movements in the xy plane, you can really choose the orientation on this as long as you configure the wires on the motor correctly