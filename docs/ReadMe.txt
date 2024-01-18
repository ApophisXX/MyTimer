This library is a simple way to take advantage the builtin arduino function: millis() 

The systemfunction of arduino keeps track of the time in milliseconds that has been passed since the board hast powered and your code started running. 


This library provides different timing functions, as listed below.

Created by - ApophisXX

Thanks to @redditUser   - LovableSidekick
                        - xyzzy1337

###### Created 30.11.2021 ########
###### last Changed 18.01.2024 ########

Provided functions:

****#### For class MyTimer ####****


****#### pos ####****
This function gives you a positive edge result everytime the setted time expires. 
It then resets itself for the next period to expire. 
Return: bool
Parameter:  - long Interval: - explains itself (in milliseconds)
            - bool Start:    - true: starts the timer 
                             - false: stops the timer
Example for usage: If you want to get a Serial.print every - lets say 500ms.

****#### setDelayedOn ####****
This function gives you a positive result once your setted time has expired.
Unlike "pos" it does not resets itself so it stays on the whole time until you stop it by setting the Start parameter to false.
Return: bool
Parameter:  - long Delay: explains itself (in milliseconds)
            - bool Start:   - true: starts the timer 
                            - false: stops the timer
Example for usage: If you want a led to turn on, once a point in time has arrived.

****#### blinkOnOff ####****
This function gives you a toggleing bool result everytime the setted time has expired.
You can adjust the time it returns TRUE and FALSE independently.
Return: bool
Parameter:  - long TimeOn:  - Time the return is TRUE (in milliseconds)
            - long TimeOff: - Time the return is FALSE (in milliseconds)
            - bool Start:   - true: starts the timer 
                            - false: stops the timer
Example for usage: If you want to blink any kind of led or so for 500ms on and 300ms off.

****#### intervalAdd ####****
This function gives you the possibility of a time dependent counter. You can start counting from various starting point until an endpoint. Then it starts over again.
Return: int
Parameter:  - int LowerEnd:  - Starting point
            - int UpperEnd:  - End point
            - StartValue:    - point to start counting from.
            - IncrBy:        - the value the integer is incremented by
            - long Interval: - explains itself (in milliseconds)
            - bool Start:   - true: starts the timer 
                            - false: stops the timer
Example for usage: If you want a INTEGER repeadetly count from 20 
to 100 in 500ms steps. For whatever its useful...I took it for some Modeswitching of Neopixel effects. 



****#### For class MyTimerPin ####****

****#### blinkPin ####****

This function toggles a specific PIN of your board, without the need to determine the PIN as an OUTPUT
The the result changes its values evenly. (Like 500ms On - 500ms Off)
Parameter:  - long Interval: - explains itself (in milliseconds)
            - bool Start:   - true: starts the timer 
                            - false: stops the timer
Example for usage: If you want to blink a led evenly.


****#### For class MyTimerSerial ####****

****#### begin ####****
This function needs to be called once in the setup() function of your code, to establish Serial communication.
Parameter:  - long baud: sets a specific baud rate (You know, its like Serial.begin(); :D )

Example for usage: There is no example, its necessary, otherwise it wont work. 

****#### IntervalSend ####****
This function sends a value of String like "Hello World!" everytime a setted timer expires.
Parameter:  - long Interval: - explains itself (in milliseconds)
            - String: - a value you want to send via Serial.println();

Example: If you want to track a special value but you dont want the serial monitor to overload.


****#### For class MyTimerButton ####****

MyTimerButton gives you the possibility to debounce a button, that is connected to a specific pin. At first you need to create an instance of your button to provide a PIN number of your board (Where the button is connected to) and a so called CoolDown time. (Thats the time, for the button to debounce - within that period of time the button will not detect any more toggles)

Example: MyTimerButton Button_1(1, 45);
Explanation: Debounce a Button named "Button_1", that is connected to PIN 1 of your board, with a time of 45 millisecons.

****#### begin ####****

This function needs to be called once in the setup() function of your code, to initialise the button if its a normal INPUT (Button connected to 5 volts).
Return: None
Parameter: None

****#### beginPullUp ####****

This function needs to be called once in the setup() function of your code, to initialise the button if its a INPUT_PULLUP (Button connected to GND).
Return: None
Parameter: None

****#### activateSnapIn ####****

This function needs to be called once in the setup() function of your code.
It is to activate the Snap In function of this Button for a continous mode of the function rising().
Return: None
Parameter:  unsigned long startAfter - the time after that the function starts
            int fasterSteps - after how many steps the function increases in speed
            uint8_t slowBPS - the steps per second in slow mode
            uint8_t fastBPS - the steps per second in fast mode

****#### rising ####****

This function gives you a positive edge result everytime the button is pressed.
Return: bool
Parameter: None
Example for usage: If you want to trigger a "One-Time_Event" at the moment you press the button.

****#### falling ####****

This function gives you a negative edge result everytime the button is released.
Return: bool
Parameter: None
Example for usage: If you want to trigger a "One-Time_Event" at the moment you release the button.

****#### pressed ####****

This function gives you a positive result while the button is pressed, but at least as long as you´ve setted the debounce time.
Return: bool
Parameter: None
Example for usage: If you want to trigger an event, as long as you keep the button pressed.

****#### released ####****

This function gives you a positive result while the button is not pressed, but at least as long as you´ve setted the debounce time.
Return: bool
Parameter: None
Example for usage: If you want to trigger an event, as long as you do not push the button.

****#### toggled ####****

This function gives you a changing result everytime the button is pressed. The result switches from TRUE to FALSE (HIGH to LOW) everytime you push the button.
Return: bool
Parameter: None
Example for usage: If you want to switch something on, like an led.

****#### modeSwitch ####****

This function gives you the possibility to switch throgh numbers by pushing the button.
You can adjust the Starting point as well as the End Point and where to start from.
Return: uint16_t
Parameter:  - uint16_t LowerEnd: The point to go to, after overgoing the end.
            - uint16_t StartFrom: The point to start from (Start value from the beginning)
            - uint16_t UpperEnd: upper limit of the counter
Example for usage: If you want to switch through numbers by pushing a button.
I've used it for a simple LED lamp to switch through different modes.


If anybody figures out any issues, dont hesitate and tell me.

If you notice any grammarly or other mistakes in this ReadME, please consider im a non native english writer. 
So please be kind.

ApophisXX - 10.10.2023
