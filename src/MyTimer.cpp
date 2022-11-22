/*
  MyTimer.cpp - 
*/
#include "MyTimer.h"

MyTimer::MyTimer()
{

}

bool MyTimer::POS(long Interval, unsigned long SystemMillis, bool Start){
  _Interval = Interval;
  _currentMillis = SystemMillis;

if (Start == false) {
  _previousMillis = _currentMillis;
  }

if ((_currentMillis - _previousMillis >= _Interval) && Start == true) {
    _previousMillis = _currentMillis;
    return true;
  }else return false;
}

bool MyTimer::NEG(long Interval, unsigned long SystemMillis, bool Start){
  _Interval = Interval;
  _currentMillis = SystemMillis;

if (Start == false) {
  _previousMillis = _currentMillis;
  }

if ((_currentMillis - _previousMillis >= _Interval) && Start == true) {
    _previousMillis = _currentMillis;
    return false;
  }
return true;
}

bool MyTimer::DELAY_ON(long DelayMillis, unsigned long SystemMillis, bool StartMerker){
  _DelayMillis = DelayMillis;
  _currentMillis = SystemMillis;
  _merker = StartMerker;

if(_merker == false){
  _previousMillis = _currentMillis;
  return false;
}

if (_currentMillis - _previousMillis >= _DelayMillis) {
    return true;
  }
return false;
}

bool MyTimer::BLINK_BOOL(long Interval, unsigned long SystemMillis, bool Start){
  _Interval = Interval;
  _currentMillis = SystemMillis;

if(Start == false){
  _previousMillis = _currentMillis;
  _merker = false;
}

if(Start == true){
  if ((_currentMillis - _previousMillis >= _Interval) && _merker == false) {
    _previousMillis = _currentMillis;
    _merker = true;
    return _merker;
    }

  if ((_currentMillis - _previousMillis >= _Interval) && _merker == true) {
    _previousMillis = _currentMillis;
    _merker = false;
    return _merker;
    }

  }
return _merker;
}

bool MyTimer::BLINK_ON_OFF(long IntervalON, long IntervalOFF, unsigned long SystemMillis, bool Start){
  _IntervalON = IntervalON;
  _IntervalOFF = IntervalOFF;
  _currentMillis = SystemMillis;

if(Start == false){
  _previousMillis = _currentMillis;
  _merker = false;
}

if(Start == true){
  if ((_currentMillis - _previousMillis >= _IntervalON) && _merker == false) {
    _previousMillis = _currentMillis;
    _merker = true;
    return _merker;
    }

  if ((_currentMillis - _previousMillis >= _IntervalOFF) && _merker == true) {
    _previousMillis = _currentMillis;
    _merker = false;
    return _merker;
    }

  }
return _merker;
}

int MyTimer::ADD(int LowerEnd, int UpperEnd, int StartValue, int IncrBy, long Interval, unsigned long SystemMillis, bool Start){
  _Interval = Interval;
  _currentMillis = SystemMillis;

if (Start == false) {
  _previousMillis = _currentMillis;
  _value = StartValue;
  _config = false;
  return StartValue;
  }

if (Start == true && _config == false) {
  _previousMillis = _currentMillis;
  _value = StartValue +IncrBy;
  _config = true;
  }

if ((_currentMillis - _previousMillis >= _Interval) && Start == true) {
    _previousMillis = _currentMillis;
    _value = _value + IncrBy;
  }

if(_value > UpperEnd){
_value = LowerEnd;
}
if(_value < LowerEnd){
_value = UpperEnd;
}
return _value;
}

bool MyTimer::RANDOM_POS(unsigned long min, unsigned long max, unsigned long SystemMillis, bool Start){
 _currentMillis = SystemMillis;

if (Start == false) {
  _previousMillis = _currentMillis;
  }  
if (Start == true && _merker == false) {
  _Interval = random(min, max);
  _merker = true;
  }
if ((_currentMillis - _previousMillis >= _Interval) && Start == true) {
    _previousMillis = _currentMillis;
    _merker = false;
    return true;
  }else return false;
}

MyTimerPin::MyTimerPin(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void MyTimerPin::BLINK_PIN(long Interval, unsigned long SystemMillis, bool Start)
{
   _Interval = Interval;
   _currentMillis = SystemMillis;

   if(Start == false){
  _previousMillis = _currentMillis;
  _merker = false;
}

if(Start == true){
  if ((_currentMillis - _previousMillis >= _Interval) && _merker == false) {
    _previousMillis = _currentMillis;
    digitalWrite(_pin, HIGH);
    _merker = true;
    }

  if ((_currentMillis - _previousMillis >= _Interval) && _merker == true) {
    _previousMillis = _currentMillis;
    digitalWrite(_pin, LOW);
    _merker = false;
    }

  }
}

MyTimerSerial::MyTimerSerial(HardwareSerial *serIn)
{
  _Serial = NULL;
  _ser = serIn;
}

void MyTimerSerial::begin( long baud)
{
  _baud = baud;
   _Serial = _ser;
  _Serial->begin(_baud);
  _Serial->println("Ready to Rip!");
}

void MyTimerSerial::IntervalSend(long Interval, unsigned long SystemMillis, String str)
{
   _Interval = Interval;
   _currentMillis = SystemMillis;

   if (_currentMillis - _previousMillis >= _Interval) {
    _previousMillis = _currentMillis;
    _Serial->println(str);
    } 
}
