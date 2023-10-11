#include <Arduino.h>
#include <MyTimer.h>
/****************************************************************
At first you need to create an instance with any name you want to.
In my case I named it SerialPrintTimer, beacause i want to send "Hello World!"
to the serial monitor and I want the name to be meaningful for its purpose.

Of course you have to initialise the Serial communication, I think there is no
need for me to explain.

In the last step, I take a function of MyTimer lib that matches my needs. In my case the function pos.
The function pos has a set of two parameters. One is the interval, and the second is the start condition.

In my case the Interval is set to 500ms and the start condition is simply true.

So, now, every 500ms, we get a "Hello World!" written in our serial monitor.

****************************************************************/

MyTimer SerialPrintTimer; 

void setup() {
Serial.begin(115200);
}

void loop() {

if(SerialPrintTimer.pos(500, true)){
  Serial.println("Hello World!");
}

}