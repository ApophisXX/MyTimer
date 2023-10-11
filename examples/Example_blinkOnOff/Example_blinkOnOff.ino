#include <Arduino.h>
#include <MyTimer.h>
/****************************************************************
At first you need to create an instance with any name you want to.
In my case I simply named it "LED_BLINK", beacause i want a LED to blink.

For better understanding, i also created a variable named "blink".

In the last step, I take a function of MyTimer lib that matches my needs. In my case the function blinkOnOff.
The function blinkOnOff has a set of three parameters.

The first is TimeOn, it specifies the time you want the led to be on, in my case 500ms.

The second is TimeOff, it specifies the time you want the led to be off, in my case 300ms.

The third is the start condition - it specifies the function whether to start or not.
In my case, the start condition is simply "true".

Now the LED "LED_BUILTIN" turns on for 500ms and then turns off for 300ms and then turns on again....and so on.

And its completly done, without stopping the code, like delay would do.
****************************************************************/
MyTimer LED_BLINK;

bool blink;

void setup() {

}

void loop() {

blink = LED_BLINK.blinkOnOff(500, 300, true);

if(blink == true){
  digitalWrite(LED_BUILTIN, HIGH);
  }else {digitalWrite(LED_BUILTIN, LOW);}

/* for a more advanced way to do the same thing, here is a simplified code that does the same, but looks way cooler */

//digitalWrite(LED_BUILTIN, LED_BLINK.blinkOnOff(500, 300, true));

}
