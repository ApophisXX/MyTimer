
This library is for a better usage of non-blocking millis Timer.

It provides different functions, as listed below.

Created by - ApophisXX

###### 30.11.2021 ########

Provided functions:

For class MyTimer

POS			- positive bool result for one Cycle		
NEG			- negative bool result for one Cycle
DELAY_ON		- delayed bool result
BLINK_BOOL		- blink bool in symmetrical order (f.e. 500ms On 500ms off)
BLINK_ON_OFF		- as BLINK_BOOL, but with adjustable On and Off Time
BLINK_PIN		- as BLINK_BOOL, but for Output pins (no need for the PIN to be set up as Output in void SETUP)
ADD			- a simple addition function, you can set up the upper and lower end, the starting point and the interval
RANDOM_POS		- as POS, but with adjustable randomness




For class MyTimerPin

BLINK_PIN		- as BLINK_BOOL, but for Output pins (no need for the PIN to be set up as Output in void SETUP)




For class MyTimerSerial

begin			- initialize the Serial communication
IntervalSend		- sends a string in an adjustable interval, through the defined serial port  


####### EXAMPLES ########

#include <MyTimer.h>

MyTimer Timer1;
MyTimerPin Timer2(BUILTIN_LED);
MyTimerSerial IntervalSerial(&Serial); //declare a instance of the class MyTimerSerial
                                       //and attach the Serial to it

byte i = 0;                 //just a test value
String TextOrVariable;      //a String variable, just for testing purposes

void setup() {
  IntervalSerial.begin(115200); //initialize the Serial communication to our instance
                                //set a baud rate 
}

void loop() {
if(Timer1.POS(1000, millis(), true))
{
  i++;    //Every second, we're increasing the value of the BYTE i by one.. 
}         //because its a byte, it only goes to 255, then it's set to zero by itself

Timer2.BLINK_PIN(1500, millis(), true); //every 150ms, the builtin LED gets toggled
                                       //BLINK_PIN -> function of class MyTimerPin


IntervalSerial.IntervalSend(500, millis(), String(i));  //sends a string through the defined serial port 
                                                          //every 500ms 

}

//just play around a little bit...
//set them values dynamically, like for example increasing or decreasing the IntervalSend value according to the value of i.

//IntervalSerial.IntervalSend((500 - i), millis(), String(i));
//so while i increases, the interval gets shorter and shorter