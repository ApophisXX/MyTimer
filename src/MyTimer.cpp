/*
  MyTimer.cpp -
*/

#include "Arduino.h"
#include "MyTimer.h"

MyTimer::MyTimer()
{
}

bool MyTimer::pos(long Interval, bool Start)
{
  _Interval = Interval;
  _currentMillis = millis();

  if (Start == false)
  {
    _previousMillis = _currentMillis;
  }

  if ((_currentMillis - _previousMillis >= _Interval) && Start == true)
  {
    _previousMillis = _currentMillis;
    return true;
  }
  else
    return false;
}

bool MyTimer::setDelayedOn(long Delay, bool Start)
{
  _DelayMillis = Delay;
  _currentMillis = millis();
  _merker = Start;

  if (_merker == false)
  {
    _previousMillis = _currentMillis;
    return false;
  }

  if (_currentMillis - _previousMillis >= _DelayMillis)
  {
    return true;
  }
  return false;
}

bool MyTimer::blinkOnOff(long TimeOn, long TimeOff, bool Start)
{
  _IntervalON = TimeOn;
  _IntervalOFF = TimeOff;
  _currentMillis = millis();

  if (Start == false)
  {
    _previousMillis = _currentMillis;
    _merker = false;
  }

  if (Start == true)
  {
    if ((_currentMillis - _previousMillis >= _IntervalOFF) && _merker == false)
    {
      _previousMillis = _currentMillis;
      _merker = true;
    }

    if ((_currentMillis - _previousMillis >= _IntervalON) && _merker == true)
    {
      _previousMillis = _currentMillis;
      _merker = false;
    }
  }
  return _merker;
}

int MyTimer::intervalAdd(int LowerEnd, int UpperEnd, int StartValue, int IncrBy, long Interval, bool Start)
{
  _Interval = Interval;
  _currentMillis = millis();

  if (Start == false)
  {
    _previousMillis = 0;
    _value = StartValue;
    _config = false;
    return StartValue;
  }

  if (Start == true && _config == false)
  {
    _previousMillis = _currentMillis;
    _value = StartValue + IncrBy;
    _config = true;
  }

  if ((_currentMillis - _previousMillis >= _Interval) && Start == true)
  {
    _previousMillis = _currentMillis;
    _value = _value + IncrBy;
  }

  if (_value > UpperEnd)
  {
    _value = LowerEnd;
  }
  if (_value < LowerEnd)
  {
    _value = UpperEnd;
  }
  return _value;
}






