#include "Arduino.h"
#include "MyTimer.h"

MyTimerSerial::MyTimerSerial(HardwareSerial *serIn)
{
  _Serial = NULL;
  _ser = serIn;
}

void MyTimerSerial::begin(long baud)
{
  _baud = baud;
  _Serial = _ser;
  _Serial->begin(_baud);
  _Serial->println("Ready to Rip!");
}

void MyTimerSerial::IntervalSend(long Interval, String str)
{
  _Interval = Interval;
  _currentMillis = millis();

  if (_currentMillis - _previousMillis >= _Interval)
  {
    _previousMillis = _currentMillis;
    _Serial->println(str);
  }
}