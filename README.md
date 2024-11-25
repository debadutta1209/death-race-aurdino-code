Death Race Arduino Project
This project is a Death Race control system built using an Arduino, an L298N motor driver, and a Flysky FS-i6 remote control. The system processes pulse width modulation (PWM) signals from the remote to control the direction and speed of two motors, enabling precise vehicle navigation.

Features
Forward and Backward Movement: Adjusted based on PWM signals from the remote.
Left and Right Turns: Smooth directional changes by controlling motor direction and speed.
Stop Functionality: Halts all motor movement when in neutral signal zones.
Debugging Support: Prints pulse width and movement direction to the serial monitor for real-time monitoring.
Hardware Requirements
Arduino Board (e.g., Uno, Nano, etc.)
L298N Motor Driver
Two DC Motors
Flysky FS-i6 Remote Control
Power Supply for Motors (e.g., battery pack)
Connecting Wires
Pin Configuration
![image](https://github.com/user-attachments/assets/67bfc5d1-55e0-4373-9c2b-101ed99b4c6a)
Code Explanation
Signal Reading:

The pulseIn() function reads PWM signals from the Flysky remote on ch1Pin and ch2Pin.
These signals determine the movement or stopping of the motors.
Motor Control:

The L298N driver handles motor direction and speed through PWM and digital control signals.
Predefined thresholds for ch1Value and ch2Value dictate forward, backward, left, or right movement.
Serial Debugging:

The code continuously logs the values of ch1Value and ch2Value for monitoring and troubleshooting.
Functions:

Forward(): Moves both motors forward.
Backward(): Reverses both motors.
Left(): Turns left by reversing Motor B and moving Motor A forward.
Right(): Turns right by reversing Motor A and moving Motor B forward.
Stop(): Stops all motor activity.
Setup Instructions
Hardware Connections:

Connect the motors to the L298N motor driver.
Wire the Arduino pins to the respective inputs on the L298N.
Link the Flysky receiver to the Arduino (ch1Pin and ch2Pin).
Software Setup:

Install the Arduino IDE from Arduino.
Open the provided code and upload it to your Arduino.
Power Up:

Connect the power supply to the L298N motor driver.
Ensure the Flysky remote and receiver are paired and operational.
How to Use
Turn on the Flysky remote and vehicle power supply.
Use the joystick to control the vehicle:
Forward: Push the vertical joystick up.
Backward: Pull the vertical joystick down.
Left: Move the horizontal joystick left.
Right: Move the horizontal joystick right.
Return both joysticks to the center to stop.
Debugging
Use the Arduino IDE Serial Monitor (9600 baud rate) to observe pulse widths and debug motor behavior.
Future Improvements
Add speed control with varying PWM signals for gradual acceleration and deceleration.
Implement obstacle detection using sensors.
Introduce autonomous or semi-autonomous navigation modes.
