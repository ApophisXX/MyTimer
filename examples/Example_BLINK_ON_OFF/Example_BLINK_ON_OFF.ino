#include <Arduino.h>
#include <MyTimer.h>

MyTimer TIMER1;

bool LED_BLINK;

void setup() {
Serial.begin(115200);
}

void loop() {

 /* Blinking LED, with adjustable on and off time */ 

LED_BLINK = TIMER1.BLINK_ON_OFF(550, 250, millis(), true);

if(LED_BLINK == true){
  digitalWrite(LED_BUILTIN, HIGH);
  }else {digitalWrite(LED_BUILTIN, LOW);}

}
