The tracking car uses an ESP32 as its main control board, and an N20 motor. It is externally powered by a 7.4V battery, and the motor driver chip is the RZ7899.The wheels are 60mm diameter polyurethane wheels, and it uses a five-path tracking system for line tracing.

After initialization in the code section, the Bluetooth data is first read to obtain the question number and coordinates, and then the current question is executed accordingly.

For the tracking section, when moving straight, the sensor data is read. If the left side detects a black line, it indicates that the car is leaning to the left, so the speed of the left wheel is increased to achieve the purpose of moving in a straight line. The same applies to the right side.
When making a turn, to compensate for the impact of inertia, the car reverses a certain distance before turning. After detecting the black line, the turning is stopped after a preset delay, and the car continues moving straight.
