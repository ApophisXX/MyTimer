#include "Arduino.h"
#include "MyTimer.h"

MyTimerPin::MyTimerPin(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void MyTimerPin::blinkPin(long Interval, bool Start)
{
  _Interval = Interval;
  _currentMillis = millis();

  if (Start == false)
  {
    _previousMillis = _currentMillis;
    _merker = false;
  }

  if (Start == true)
  {
    if ((_currentMillis - _previousMillis >= _Interval) && _merker == false)
    {
      _previousMillis = _currentMillis;
      digitalWrite(_pin, HIGH);
      _merker = true;
    }

    if ((_currentMillis - _previousMillis >= _Interval) && _merker == true)
    {
      _previousMillis = _currentMillis;
      digitalWrite(_pin, LOW);
      _merker = false;
    }
  }
}