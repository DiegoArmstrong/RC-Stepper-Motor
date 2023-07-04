# RC Stepper Motor

# Project Description

In this project, I developed a system to control a stepper motor's angle and direction using the Arduino Uno and DRV8825 driver. The goal was to create an intuitive user interface using Python's Tkinter library, enabling users to adjust the stepper motor's position and direction with ease.

The project involved wiring the Arduino Uno and DRV8825 driver, establishing the necessary connections with the stepper motor, and implementing the control logic. The Python-based GUI developed with Tkinter allowed users to interact with the system, specifying the desired angle and direction for the stepper motor.

# Hardware Understanding

Before you start creating or even thinking about your circuits, you first need to understand what kind of stepper motor you have and what that means for your circuit. The most common stepper motors are usually either 4-wired, 6-wired, or 8-wired. 

![Untitled design](https://github.com/DiegoArmstrong/RC-Stepper-Motor/assets/74511707/dbb72af6-66a8-4008-947f-8e9e7fa6b1b1)

Stepper motors can also be either Unipolar or Bipolar. Bipolar motors generally have more torque and are more efficient than unipolar motors. In contrast, unipolar motors use only half of each winding coil at a given time, resulting in lower torque and efficiency.

The DRV8825 is intended for 4-wire bipolar stepper motors. So what do you do if you have a stepper motor with more wires? Well, in a 4-wire motor, one coil is connected via a positive and negative side. The easiest way to think about it is that this coil is represented by a pair of pins on your stepper motor. 6 and 8 wire motors have what are called center taps in between these pairs. These center taps are intended for high-torque purposes and we do not need them. So you simply connect your 6 or 8-wire stepper motor as if it were a 4-wire Bipolar motor. To do this you skip the center taps as such…

(A+ goes with A- |  B+ goes with B-)    We skip ACT and BCT (A Center Tap, B Center Tap).
