# Smart_Home
The system allows controlling the home by mobile phone application through Bluetooth [UART Terminal with TTL].
The system supports 5 users with different names and passwords.
In case of entering the username and password 3 times wrong, the system should give an alarm.

The project is based on Layered Architecture and operates inside a Super Loop.
Files:
Application Layer:
main.c
Hardware Abstraction Layer[HAL]:
Bluetooth_Module: Driver for HC-05 Bluetooth module and is used for interfacing with mobile phone
SERVO: Driver used to control the Servo Motor 4. DC Motor: Driver used to control the DC Motor
SIREN: Driver used to make a siren sound from the buzzer
LED: Driver used to Control the LED
Microcontroller Abstraction Layer[MCAL]:
DIO: Driver used to control the GPIO pins
TIMERS: Driver used for controlling timers for Servor and Buzzer
UART: Driver used for interfacing with the UART peripheral for Bluetooth communications
Library Layer[LIB]:
BIT_MACROS: Contains bit-wise operations
STD_TYPES: Contains all the data types used
