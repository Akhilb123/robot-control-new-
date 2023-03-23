# robot-control-new-
### fire extinguisher robot
This is a basic Arduino robot project. components used are Arduino UNO, connecting wires, IR sensors, Servo Motor, Breadboard, L293D motor Driver module. The Arduino Uno can be used to connect with sensors that detect the presence of fire and then regulate the movement of the robot to approach and extinguish the fire using a pump or other mechanisms in the case of a fire extinguisher robot. The microcontroller can also be used to regulate the speed and direction of the robot's motors, as well as the placement of any servos needed to aim the water or other extinguishing agent at the fire. The IR sensors are used to detect fire. 3 infra red sensors are used here. one at the front and other two on both sides. We can use the motors to move in the proper direction of the fire by operating the motors through the L293D module. water can be carried in a small can to put out the fire.

### The fire sensor will output HIGH when there is no fire and output LOW when there is fire. If no fire is there we ask the motors to remain to stop by making all the pins high as shown below :
     if (digitalRead(LeftSidesensor) ==1 && digitalRead(RightSidesensor)==1 && digitalRead(Frontsidesensor) ==1) //If Fire not detected all sensors are zero
     {
     //Do not move the robot
     digitalWrite(LM1, HIGH);
     digitalWrite(LM2, HIGH);
     digitalWrite(RM1, HIGH);
     digitalWrite(RM2, HIGH);
     }
#### if there is any fire we can ask the robot to move in that direction by rotating the respective motor.
