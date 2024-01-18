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

For this example, we also need to execute a function called...

   - .activateSnapIn();

This function activates the continous mode for this Button.
That means, if you push this Button and keep it pressed the function - .rising() is repeatedly working.

For activateSnapIn you need to provide some additional constants.

    unsigned long startAfter = the time after that the button starts the function
    int fasterSteps = after how many steps, the function increases in speed
    uint8_t slowBPS = the steps per second in slow mode 
    uint8_t fastBPS = the steps per second in fast mode



What is it useful for?

Simlyfied example: You want to increase a variable, lets say, like brightness of an LED.
If you keep the button pressed, its starts to increasing first slowly, and then it goes faster. 
(Like the Volume settings at you TV)

Now, to show you how all that works....

My variable "TestInteger" is initialised with the value 0;


IMPORTANT
THE START TIME (startAfter) CANNOT BE LESS THAN THE COOLDOWN TIME.
THE xBPS CANNOT BE 0. 
OTHERWISE THE FUNCTION WILL NOT START.

RESULT

If you've uploaded the program to you controller, you should see the INTEGER increasing once,
everytime you press the button. If you hold the button down for longer than 1 second (startAfter = 1000ms)
it starts increasing repeatedly. At first with two times a second (500ms) and after it has increased 10 times
it starts doing it faster with 5 times a second.

****************************************************************/

MyTimerButton
    Button_1(2, 200); // provide PIN Number an debounce time (in ms) for your instance

int TestInteger = 0;

void setup()
{
    Serial.begin(115200);
    Button_1.beginPullUp();
    Button_1.activateSnapIn(1000, 10, 5, 10);
}

void loop()
{
    
    if (Button_1.rising())
    {
        TestInteger = TestInteger + 1;
        Serial.println(TestInteger);
    }
}
