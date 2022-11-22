#include <Arduino.h>
#include <MyTimer.h>

MyTimer TIMER1, TIMER2;

int MODE;

void setup() {
Serial.begin(115200);
}

void loop() {

/* Every 2 seconds, the variable MODE gets increased, beginning from 1 to 10, starting at 4 and increased by 1 */ 

 /* Every 500ms, we get a Serial.println */ 

MODE = TIMER1.ADD(1, 10, 4, 1, 2000, millis(), true);

if(TIMER2.POS(500, millis(), true) == true){
  Serial.println(MODE);
}

}
