#include <Arduino.h>
#include <MyTimer.h>
/****************************************************************

One of the coolest and easiest ways to implement a Button into your project is the function called "toogle".
It gives you a alternating result everytime the button is pressed. 
The result switches from TRUE to FALSE (HIGH to LOW) everytime you push the button.

So its a fast and easy way to turn anything on and off.

At first you need to create an instance for every button you want to connect.
You can use any name you want to. In my case I simply named it Button_1.
For the instance you need to provide two parameters. The PIN number, to which the button is connected,
and a coolDown time. This is the time, you want the button to debounce.
Debounce..? What does that mean?

Electrical contacts in mechanical pushbutton switches often make and break contact
several times when the button is first pushed. Debouncing removes the resulting ripple signal,
and provides a clean transition at its output.

Within the setup code you have to initialise the buttons first. There are two types.
- .beginPullUp(); When your button is connected to ground.
- .begin(); When your button is connected to 5V.

Now, to show you how all that works....

The method (or easier to say the function) toggle is used by Button_1 (connected to pin 3). 
The function has no extra parameters.
So everytime you push the button, the result is alternating between true and false (HIGH and LOW).

In my case I want to toogle an LED On and Off.

****************************************************************/

MyTimerButton
    Button_1(3, 20); // provide PIN Number an debounce time (in ms) for your instance

void setup()
{
    Button_1.beginPullUp();
}

void loop()
{
digitalWrite(LED_BUILTIN, Button_1.toggled());
}
