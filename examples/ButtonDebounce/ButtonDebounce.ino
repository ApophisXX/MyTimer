#include <Arduino.h>
#include <MyTimer.h>

//Create an instance of class MyTimerButton for every button you want to use.
uint16_t TestInteger = 0;


MyTimerButton 
  Button_0(0, 20), //provide PIN Number an debounce time (in ms) for your instance
  Button_1(1, 20), //provide PIN Number an debounce time (in ms) for your instance
  Button_2(2, 20); //provide PIN Number an debounce time (in ms) for your instance


void setup() {
  Serial.begin(115200);
  Button_0.beginPullUp();   //decide whether its a logical PULLUP or PULLDOWN button
  Button_1.beginPullDown(); //decide whether its a logical PULLUP or PULLDOWN button
  Button_2.beginPullUp();   //decide whether its a logical PULLUP or PULLDOWN button
}

void loop() {
  /*
  Provide millis() for every instance of the buttons at the beginning of the loop. For time critical applications, you should consider 
  to provide the actual timestamp of the system (millis()) right before you use these instance in any form.

  As shown for Button_2 below.
  
  */
  Button_0.setSystemMillis(millis()); 
  Button_1.setSystemMillis(millis());

  TestInteger = Button_0.modeSwitch(1, 3, 5); 
  /* 
    every time you press Button_1 the variable TestInteger increases, beginning at 
    3, up to 5 and after that overflowing to 1. 
  */

  if(Button_1.pressed()){
    Serial.println("Button 1 - pressed");
  }
  if(Button_1.released()){
    Serial.println("Button 1 - released");
  }

  Button_2.setSystemMillis(millis());
  if(!Button_2.toggled()){
    digitalWrite(LED_BUILTIN, LOW);
  }
  if(Button_2.toggled()){
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
