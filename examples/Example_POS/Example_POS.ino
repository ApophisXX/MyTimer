#include <Arduino.h>
#include <MyTimer.h>

MyTimer TIMER1;


void setup() {
Serial.begin(115200);
}

void loop() {

 /* Every 500ms, we get a Serial.println */ 

if(TIMER1.POS(500, millis(), true) == true){
  Serial.println("POS");
}

}
