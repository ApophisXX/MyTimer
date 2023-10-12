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
    if ((_currentMillis - _previousMillis >= _IntervalON) && _merker == false)
    {
      _previousMillis = _currentMillis;
      _merker = true;
      return _merker;
    }

    if ((_currentMillis - _previousMillis >= _IntervalOFF) && _merker == true)
    {
      _previousMillis = _currentMillis;
      _merker = false;
      return _merker;
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

MyTimerButton::MyTimerButton(int pin, long CoolDown)
{
  _pin = pin;
  _CoolDown = CoolDown;
}

void MyTimerButton::begin()
{
  if (_pin >= 0 && !_Begun)
    pinMode(_pin, INPUT);
  _Begun = true;
}

void MyTimerButton::beginPullUp()
{
  if (_pin > 0 && !_PullUpBegun)
    pinMode(_pin, INPUT_PULLUP);
  _PullUpBegun = true;
}

bool MyTimerButton::rising()
{
  ri_pressed = false;
  _currentMillis = millis();
  if (_PullUpBegun)
  {
    if (digitalRead(_pin) == LOW)
    {
      ri_pressed = true;
    }
  }
  if (_Begun)
  {
    if (digitalRead(_pin) == HIGH)
    {
      ri_pressed = true;
    }
  }

  if (ri_pressed && !ri_blocked)
  {
    ri_previousMillis = _currentMillis;
    ri_blocked = true;
    return true;
  }
  if ((_currentMillis - ri_previousMillis >= _CoolDown) && ri_blocked && !ri_pressed)
  {
    ri_blocked = false;
    return false;
  }
  return false;
}

bool MyTimerButton::falling()
{
  fa_pressed = false;
  _currentMillis = millis();
  if (_PullUpBegun)
  {
    if (digitalRead(_pin) == LOW)
    {
      fa_pressed = true;
    }
  }
  if (_Begun)
  {
    if (digitalRead(_pin) == HIGH)
    {
      fa_blocked = true;
    }
  }

  if (fa_pressed && !fa_blocked)
  {
    fa_previousMillis = _currentMillis;
    fa_blocked = true;
    return false;
  }
  if ((_currentMillis - fa_previousMillis >= _CoolDown) && fa_blocked && !fa_pressed)
  {
    fa_blocked = false;
    return true;
  }
  return false;
}

bool MyTimerButton::pressed()
{
  pr_pressed = false;
  _currentMillis = millis();
  if (_PullUpBegun)
  {
    if (digitalRead(_pin) == LOW)
    {
      pr_pressed = true;
    }
  }
  if (_Begun)
  {
    if (digitalRead(_pin) == HIGH)
    {
      pr_pressed = true;
    }
  }

  if (pr_pressed)
  {
    pr_previousMillis = _currentMillis;
    pr_blocked = true;
  }
  if ((_currentMillis - pr_previousMillis >= _CoolDown) && !pr_pressed)
  {
    pr_blocked = false;
  }
  if (pr_blocked)
    return true;
  return false;
}

bool MyTimerButton::released()
{
  re_pressed = false;
  _currentMillis = millis();
  if (_PullUpBegun)
  {
    if (digitalRead(_pin) == LOW)
    {
      re_pressed = true;
    }
  }
  if (_Begun)
  {
    if (digitalRead(_pin) == HIGH)
    {
      re_pressed = true;
    }
  }

  if (re_pressed)
  {
    re_previousMillis = _currentMillis;
    re_blocked = true;
  }
  if ((_currentMillis - re_previousMillis >= _CoolDown) && !re_pressed)
  {
    re_blocked = false;
    ;
  }
  if (pr_blocked)
    return false;
  return true;
}

bool MyTimerButton::toggled()
{
  to_pressed = false;
  _currentMillis = millis();
  if (_PullUpBegun)
  {
    if (digitalRead(_pin) == LOW)
    {
      to_pressed = true;
    }
  }
  if (_Begun)
  {
    if (digitalRead(_pin) == HIGH)
    {
      to_pressed = true;
    }
  }

  if (to_pressed && !to_blocked)
  {
    to_previousMillis = _currentMillis;
    to_blocked = true;
    toggle = !toggle;
  }

  if ((_currentMillis - to_previousMillis >= _CoolDown) && to_blocked && !to_pressed)
  {
    to_blocked = false;
  }

  if (toggle == true)
  {
    return true;
  }
  return false;
}

uint16_t MyTimerButton::modeSwitch(uint16_t LowerEnd, uint16_t StartFrom, uint16_t UpperEnd)
{
  _LowerEnd = LowerEnd;
  _UpperEnd = UpperEnd;
  _StartFrom = StartFrom;
  _currentMillis = millis();
  if (initalised == false)
  {
    initalised = true;
    _mode = _StartFrom;
  }
  mo_pressed = false;
  if (_PullUpBegun)
  {
    if (digitalRead(_pin) == LOW)
    {
      mo_pressed = true;
    }
  }
  if (_Begun)
  {
    if (digitalRead(_pin) == HIGH)
    {
      mo_pressed = true;
    }
  }

  if (mo_pressed && !mo_blocked)
  {
    mo_previousMillis = _currentMillis;
    mo_blocked = true;
    _mode = _mode + 1;
  }
  if (_mode > _UpperEnd)
  {
    _mode = _LowerEnd;
  }
  if (_mode < _LowerEnd)
  {
    _mode = _UpperEnd;
  }

  if ((_currentMillis - mo_previousMillis >= _CoolDown) && mo_blocked && !mo_pressed)
  {
    mo_blocked = false;
  }

  return _mode;
}
