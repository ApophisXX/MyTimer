#include <Arduino.h>
#include <MyTimer.h>
/****************************************************************
 * In this example I want to show you how to use a function called IntervalSerial.
 * This function gives you the possibility to Send a String, within an given Interval to the serial monitor,

This makes it more easy and comfortable to track any value, without the serial monitor to be "overflown".
(Sorry, I dont know how to explain better, but I think you know what I mean...)

So what does that mean axactly? If I want to track a value or want to know if a special part of my code works,
I send a String every (for example) 1000ms to the serial monitor.


At first you need to create an instance with any name you want to.
In my case I named it IntervalSerial. The Instance needs one parameter, and its the Hardwareserial connection of your board.

"IntervalSerial(&Serial);"

In my case I also created a variable of type String and i called it TextOrVariable. I initialised it with the value "NOTHING".

After that, I have to start the serial communication, like you do everytime, but now I use my created instance "IntervalSerial".
I also provide a specific baud rate. 

IntervalSerial.begin(115200);

Within the loop function, I set the value of my variable to "Hello World!".
Now I use the method (function) IntervalSend that needs a set of two parameters. The interval and the String.

So, now, every 1000ms, we get a "Hello World!" written in our serial monitor.

Just experiment a little and try to convert any of your variables 
to String and make it print out to the serial monitor.
This example only gives you a little hint.

****************************************************************/

MyTimerSerial IntervalSerial(&Serial);

String TextOrVariable = "NOTHING"; 

void setup() {
  IntervalSerial.begin(115200);
}

void loop() {

TextOrVariable = "Hello World!";

IntervalSerial.IntervalSend(1000, TextOrVariable);

}
