The tracking car uses an ESP32 as its main control board, and an N20 motor. It is externally powered by a 7.4V battery, and the motor driver chip is the RZ7899.The wheels are 60mm diameter polyurethane wheels, and it uses a five-path tracking system for line tracing.

After initialization in the code section, the Bluetooth data is first read to obtain the question number and coordinates, and then the current question is executed accordingly.
