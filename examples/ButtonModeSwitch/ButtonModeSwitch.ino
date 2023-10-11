#include <Arduino.h>
#include <MyTimer.h>
/****************************************************************
At first you need to create an instance for every button you want to connect.
You can use any name you want to. In my case I simply named it Button_1.
For the instance you need to provide two parameters. The PIN number, to which the button is connected,
and a coolDown time. This is the time, you want the button to debounce.
Debounce..? What does that mean?

Electrical contacts in mechanical pushbutton switches often make and break contact
several times when the button is first pushed. Debouncing removes the resulting ripple signal,
and provides a clean transition at its output.

I've also created a variable named "TestInteger", its just for explanational purposes.

Because I want my Button to send something to the serial monitor I need to initialise
the Serial communication.
I think there is no need for me to explain.

Within the setup code you have to initialise the buttons first. There are two types.
- .beginPullUp(); When your button is connected to ground.
- .begin(); When your button is connected to 5V.

Now, to show you how all that works....

My variable "TestInteger" is set by a function called "modeSwitch".
The method (or easier to say the function) modeSwitch is used by Button_1 (connected to pin 3). The function has a set of three parameters.
You can chosse a specific Lower End, where to start, and where the upper limit is.
What does that mean?
Everytime you push the Button_1, TestInteger is increased by 1, starting from 3, and it goes up to 5, and start over at 1.

So for "Button_1.modeSwitch(1, 3, 5)" -  it goes 3 -> 4 -> 5 -> 1 -> 2 -> 3 -> 4 -> 5 -> 1 -> and so on and so on...

To check wheter it works or not, I also added a function called "falling" to Button_1.
So everytime I push the button, the variable increses and when I release the button, the variable is send to the serial monitor.


****************************************************************/

MyTimerButton
    Button_1(3, 20); // provide PIN Number an debounce time (in ms) for your instance

int TestInteger;

void setup()
{
    Serial.begin(115200);
    Button_1.beginPullUp();
}

void loop()
{
    TestInteger = Button_1.modeSwitch(1, 3, 5);
    if (Button_1.falling())
    {
        Serial.println(TestInteger);
    }
}
