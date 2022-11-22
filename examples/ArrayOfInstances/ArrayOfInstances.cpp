#include <Arduino.h>
#include <MyTimer.h>

MyTimer Timer[5];           //Create an array of five instances 
MyTimerPin TimerToPIN[6] =  //Create an array of five instances 
    {
        MyTimerPin(LED_BUILTIN), //Timer attached to the builtin LED
        MyTimerPin(1),  //Timer attached to Hardware PIN 1 (for example LED)
        MyTimerPin(2),  //Timer attached to Hardware PIN 2 (for example LED)
        MyTimerPin(3),  //Timer attached to Hardware PIN 3 (for example LED)
        MyTimerPin(4),  //Timer attached to Hardware PIN 4 (for example LED)
        MyTimerPin(5),  //Timer attached to Hardware PIN 5 (for example LED)    
    };
MyTimerSerial IntervalSerial(&Serial); //declare a instance of the class MyTimerSerial
                                       //and attach the Serial to it


byte i = 0;                             //just a test value
String TextOrVariable = "NOTHING";      //a String variable, just for testing purposes

void setup() {
  IntervalSerial.begin(115200); //initialize the Serial communication to our instance
                                //set a baud rate 
}

void loop() {

TimerToPIN[0].BLINK_PIN(100, millis(), true); //reference to BUILTIN LED

TextOrVariable = "No Timer expired";

if(Timer[0].POS(500, millis(), true))
    {
        TextOrVariable = "Timer 0 expired";
    }

if(Timer[1].POS(1450, millis(), true))
    {
        TextOrVariable = "Timer 1 expired";
    }

if(Timer[2].POS(8400, millis(), true))
    {
        TextOrVariable = "Timer 2 expired";
    }



TimerToPIN[1].BLINK_PIN(150, millis(), true); //every 150ms, the PIN that been set in the instance gets toggled
TimerToPIN[2].BLINK_PIN(300, millis(), true);
TimerToPIN[3].BLINK_PIN(600, millis(), true);
TimerToPIN[4].BLINK_PIN(1200, millis(), true);
TimerToPIN[5].BLINK_PIN(2400, millis(), true);

IntervalSerial.IntervalSend(50, millis(), TextOrVariable);  //sends a string through the defined serial port 
                                                          //every 50ms 

}

//just play around a little bit...
//set them values dynamically, like for example increasing or decreasing the IntervalSend value according to the value of i.

//IntervalSerial.IntervalSend((500 - i), millis(), String(i));
//so while i increases, the interval gets shorter and shorter
