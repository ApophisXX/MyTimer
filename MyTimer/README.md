This library is for a better usage of non-blocking millis Timer.

It provides different functions, as listed below.

Created by - ApophisXX

###### 30.11.2021 ########

Provided functions:

****#### For class MyTimer ####****

POS	- positive bool result for one Cycle

NEG	- negative bool result for one Cycle

DELAY_ON - delayed bool result

BLINK_BOOL - blink bool in symmetrical order (f.e. 500ms On 500ms off)

BLINK_ON_OFF - as BLINK_BOOL, but with adjustable On and Off Time

ADD - a simple addition function, you can set up the upper and lower end, the starting point and the interval

RANDOM_POS - as POS, but with adjustable randomness



****#### For class MyTimerPin ####****

BLINK_PIN		- as BLINK_BOOL, but for Output pins (no need for the PIN to be set up as Output in void SETUP)





****#### For class MyTimerSerial ####****

begin			- initialize the Serial communication

IntervalSend		- sends a string in an adjustable interval, through the defined serial port  

