# 2496W-BENJI-public
This is the code for VRC team 2496W for the 20202-2021 season "Change Up", located in Irvine, California. We used the PROS CLI (3.14) to write the software of our robot, which we decided to name "BENJI." 

## Project Structure 
![Project Structure](https://user-images.githubusercontent.com/48425033/110836687-318bab00-8255-11eb-9881-602fbfbb963e.PNG)

The robot consists of various subsystem and the specific controllers we will be using in those subsystems are inherited. E.g., the Chassis uses a PID controller, so the PID class is inherited by the "Drive" class. 

## Subsystem Configurations

Chassis: x4 200RPM Motors with a speed gear ratio (5:3). Wheel size is 3.25 omni-wheels (middle sized omni-wheels). 
Indexer: 200RPM Motor running a customed printed sprocket with a 5.5 inch diameter. Rubber bands are looped around the sprocket to use it as a roller. 
Intakes: x2 600RPM Motors situated on the front of the chassis. 
"Fly-Wheel": 600RPM Motor running a roller on the top of our robot's tower. 



