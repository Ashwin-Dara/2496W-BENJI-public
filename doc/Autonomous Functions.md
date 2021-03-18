## Drive Functions

`void Drive::relative_move(int set, int max_velocity, int max_time);`

This is the function used to move the chassis forward relative to its current position. “set” is the distance that the chassis will move forward by. “max_velocity” will be the maximum velocity that the chassis will ever be when moving forward. “max_time” is the maximum time in milliseconds that will be given for the chassis to settle. 


`void Drive::relative_turn(int target, int max_velocity, int max_time);`

This will turn the chassis to meet the certain orientation (in degrees) that you input, which is “target.” “max_velocity” will be the maximum speed that the chassis will ever be when turning, and “max_time” is the max time that will be given to the chassis to settle when turning. 

For example, in order to move forward 18 inches and then turn 45 degrees to the right, the code will be:

```javascript
Drive drive; //instantiating the drive class


//moves the chassis forward 18 inches with a max speed of 110 with a max settle time of 1400 ms
drive.relative_move(inches_to_ticks(18), 110, 1400); 


//turns the chassis 45 degrees to the right with a max speed of 110 and a max settle time of 1 second
drive.relative_turn(45, 110, 1000);
```


## Using Odometry

1. Create instances of the "Odometry" and "Point" class. 
2. Begin the Odometry position tracking thread. 
3. Within the "Point" class there is a method to set the requested point, which is "set_req_point."
4. Use the "drive_to_point" function to move to the requested point. 

Here is an example: 

