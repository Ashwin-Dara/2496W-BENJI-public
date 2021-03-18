# 2496W-BENJI-public
This is the code for VRC team 2496W for the 20202-2021 season "Change Up", located in Irvine, California. We used the PROS CLI (3.14) developed by Purdue University to write the software of our robot, which we decided to name "BENJI." Here is the official PROS documentation: https://pros.cs.purdue.edu/v5/


## Project Structure 
![Project Structure](https://user-images.githubusercontent.com/48425033/110836687-318bab00-8255-11eb-9881-602fbfbb963e.PNG)

The robot consists of various subsystem and the specific controllers we will be using in those subsystems are inherited. E.g., the Chassis uses a PID controller, so the PID class is inherited by the "Drive" class. 


## Subsystem Configurations

- Chassis: 4 200RPM Motors with a speed gear ratio (5:3). 3.25 omni-wheels is the wheel size.  

- Indexer: 200RPM Motor running a customed printed sprocket with a 5.5 inch diameter.

- Intakes: 2 600RPM Motors on the front of the chassis (flex wheels). 

- Fly-Wheel": 600RPM Motor running a roller on the top of our robot's tower (3.9" diameter VEX sprocket). 

![image](https://user-images.githubusercontent.com/48425033/111575613-041a9200-876c-11eb-8eb4-c409ed04d873.png) 


## File Contents 

- main.cpp: main function as per the standard VEX project structure. Includes main operator control function. 
- Config.cpp: constructors for all of the electronics used on the robot.
- Drive.cpp: hosts the autonomous move functions and chassis usercontrol.
- Intake.cpp: holds the autonomous and usercontrol functions for intake/shooter subsystem.
- MAFilter.cpp: moving average filter for the IMU. 
- Odometry.cpp: includes the drive to point function and the odometry class, which tracks the absolute position of the robot. 
- PID.cpp: PID controller class definition. 
- Point.cpp: contains X and Y make the Odometry class less cluttered. Inherited by the Odometry Class. 
- Scripts: holds the code for the different autonomous paths.  

