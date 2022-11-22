#include <Arduino.h>
#include <MyTimer.h>

MyTimer Timer1;
MyTimerPin Timer2(LED_BUILTIN);
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
