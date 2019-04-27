# CarND-Controls-PID
Carlos Andres Alvarez 

Self-Driving Car Engineer Nanodegree Program

---
## Introduction
A PID controller was implemented to drive autonomously through the Udacity simulator. The desired position was given by the simulator and the controller should make the car follow that position along the track by controlling the steering angle and throttle to achieve the desired speed and position. It was given the cross track error (CTE) and the speed and with that 2 pids controllers were implemented to take down the CTE to 0 and the speed to a specific desired speed.

## Impact of P, D & I Components of the controller
The Proportional term is the one in charge to steer opposite to the car's distance to the desired point (CTE) normally the center of the lane. If the the car is left from the desired point, it will steer positive and if the car right from the point it will steer negative and proportional to that distance.

The differential term takes into account the instantaneous change of the error that helps the controller to avoid getting oscillations, in this case helps the car to get to the center without that much overshoot and without zig zagging.

The integral part of the controller helps to control external perturbations (like bias or/and drift) and to recover from them to get to the desired setpoint or in this case to get the CTE to zero. In this case it seems to not affect that much the performance in the car's behavior.

## Parameters tuning
The parameters were tuned manually to achieved a good result for going around 45 mph. As said, the I component had not much effect on this, that is why that was set to 0.1 for steering and the others were tuned. The P and D coefficients were tuned in order to avoid oscillation when possible and get in a good way the curves. The coefficients for the speed control were tuned to avoid overshot and to converge fast to the desired speed, this was made by modified primarily the P component.

The steering pid controller parameters are: 0.11,0.1,0.9
The speed pid controller is: 0.5, 0.001, 0.02


## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

Fellow students have put together a guide to Windows set-up for the project [here](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) if the environment you have set up for the Sensor Fusion projects does not work for this project. There's also an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

