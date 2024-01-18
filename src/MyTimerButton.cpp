#include "Arduino.h"
#include "MyTimer.h"

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

void MyTimerButton::activateSnapIn(unsigned long startAfter, int fasterSteps, uint8_t slowBPS, uint8_t fastBPS)
{
  _SnapInSetup = false;
  if((startAfter >= _CoolDown) && (fasterSteps > 0) && (slowBPS > 0) && (fastBPS > 0)){
    _startAfter = startAfter;
    _fasterSteps = fasterSteps;
    _slowBPS = 1000/slowBPS;
    _fastBPS = 1000/fastBPS;
    _SnapInSetup = true;
  }
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
    _Steps = _Steps + 1;
    return true;
    }
  if ((_currentMillis - ri_previousMillis >= _CoolDown) && ri_blocked && !ri_pressed)
    {
    ri_blocked = false;
    return false;
    }
      

  if(_SnapInSetup){
    if (!ri_blocked){
      stAf_previousMillis = _currentMillis;
      _SnapInActive = false;
      _Steps = 0;
      }
    if (ri_blocked && (_currentMillis - stAf_previousMillis >= _startAfter) && !_SnapInActive){
      stAf_previousMillis = _currentMillis;
      _SnapInActive = true;
      _Steps = _Steps + 1;
      return true;
      }
    if (_SnapInActive && (_currentMillis - stAf_previousMillis >= _slowBPS) && _Steps < _fasterSteps){
      stAf_previousMillis = _currentMillis;
      _Steps = _Steps + 1;
      return true;
      }
    if (_SnapInActive && (_currentMillis - stAf_previousMillis >= _fastBPS) && _Steps >= _fasterSteps){
      stAf_previousMillis = _currentMillis;
      return true;
      }
      
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