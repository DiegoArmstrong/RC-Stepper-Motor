# RC Stepper Motor

Setting the angle of a stepper motor using an Arduino Uno, DRV8825 Driver, and a tkinter GUI.

Interface)

Originally, I was debating whether I should use tkinter or Eel to create the GUI. While tkinter is much easier and quicker to use, Eel offers many more possibilities for what your GUI can look like and do, as it enables you to use web dev languages like HTML, CSS, and Javascript alongside Python. I decided on using tkinter for this project since it is much easier to use and the GUI doesn’t need to do anything very complicated, nor does it need to look pretty. Another reason why I went with tkinter is because I would eventually have to integrate my GUI with the Arduino IDE to control the stepper motor. I found a library called pyFirmata which allows you to do just that and I figured that since Eel works with 4 languages total, it could get unreasonably complicated. 

The tkinter GUI I made allows users to input desired angles and initiate motor movement. The "closest angle" displays the nearest angle value that the stepper motor is capable of, as the step size of the servo motor that I took out of an old no longer functioning machine has a step size of 1.8 degrees.

Hardware)

Most of the hardware needed for this project is pretty conventional and I found most of it in the office already. The only other necessary piece of hardware that we did not own was a stepper motor driver. I decided to go with the DRV8825 for this project as it is simple to use and most versions of the product are relatively close to 2A which matches the stepper motor I used. 

DRV8825 + Stepper Motor + Arduino configurations and usage)

  Step1: Stepper Motor Analysis)

Before you start creating or even thinking about your circuits, you need first to understand what kind of stepper motor you have and what that means for your circuit. The most common stepper motors are usually either 4-wired, 6-wired, or 8-wired. 
           

Stepper motors can also be either Unipolar or Bipolar. Bipolar motors generally have more torque and are more efficient than unipolar motors. In contrast, unipolar motors use only half of each winding coil at a given time, resulting in lower torque and efficiency.

The DRV8825 is intended for 4-wire bipolar stepper motors. So what do you do if you have a stepper motor with more wires? Well, in a 4-wire motor, one coil is connected via a positive and negative side. The easiest way to think about it is that this coil is represented by a pair of pins on your stepper motor. 6 and 8 wire motors have what are called center taps in between these pairs. These center taps are intended for high-torque purposes and we do not need them. So you simply connect your 6 or 8-wire stepper motor as if it were a 4-wire Bipolar motor. To do this you skip the center taps as such…

(A+ goes with A- |  B+ goes with B-)    We skip ACT and BCT (A Center Tap, B Center Tap).

  Step 2: Circuit)

*Add a capacitor to the circuit to avoid fluctuations in voltage and reduce electrical noise.

Make sure to adjust the current limiter appropriately to your stepper motor so as to not burn it out.  To do this, adjust the potentiometer (the screw beside the ENABLE and M0 pinouts) clockwise to lower and counter-clockwise to higher. To check the current limit, take a potentiometer and check the reference voltage (Vref)  by resting your red on the potentiometer and your black on the GND LOGIC pin. The current limit is found by the following formula…

Current Limit = Vref x 2

I found that having the current limit set at 1A worked just fine to move the motor, so adjust the current limiter until your reference voltage reads close to 0.5V.

My stepper motor was able to move smoothly with about 10 volts being applied. 

Software)

For the coding portion, I first wanted to attempt moving the stepper motor continuously with Arduino libraries to ensure that my circuit connections were correct. Then only when the stepper motor successfully moved I decided to move onto attempting to make it move at a certain angle from a chosen user input without the use of any Arduino libraries because the pyfirmata python library does not allow for the usage of Arduino libraries. Still doing it with the Arduino IDE though so as to not attempt the difficulty that comes with the GUI control too early in case it does not work since it would be much more difficult to trouble-shoot.

