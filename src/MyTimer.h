/*
  MyTimer.h - Library fpr setting up different Timer functions without delay
*/
#ifndef MyTimer_h
#define MyTimer_h

#include "Arduino.h"

class MyTimer
{
  public:
    MyTimer();
    bool POS(long Interval, unsigned long SystemMillis, bool Start);
    bool NEG(long Interval, unsigned long SystemMillis, bool Start);
    bool DELAY_ON(long DelayMillis, unsigned long SystemMillis, bool StartMerker);
    bool BLINK_BOOL(long Interval, unsigned long SystemMillis, bool Start);
    bool BLINK_ON_OFF(long IntervalON, long IntervalOFF, unsigned long SystemMillis, bool Merker);
    int ADD(int LowerEnd, int UpperEnd, int StartValue, int IncrBy, long Interval, unsigned long SystemMillis, bool Start);
    bool RANDOM_POS(unsigned long min, unsigned long max, unsigned long SystemMillis, bool Start);

  private:
    uint16_t _value;
    unsigned long _Interval, _IntervalON, _IntervalOFF, _DelayMillis;
    unsigned long _currentMillis;
    unsigned long _previousMillis = 0;
    bool _merker, _config;
    int _pin;
};

class MyTimerPin
{
  public:
    MyTimerPin(int pin);
    void BLINK_PIN(long Interval, unsigned long SystemMillis, bool Start);

  private:
    unsigned long _Interval;
    unsigned long _currentMillis;
    unsigned long _previousMillis = 0;
    bool _merker;
    int _pin;
};

class MyTimerSerial
{
  public:
    MyTimerSerial(HardwareSerial *serIn);
    void begin( long baud);
    void IntervalSend(long Interval, unsigned long SystemMillis, String str);    
  private:
    HardwareSerial *_Serial, *_ser;
    long _baud;
    unsigned long _Interval;
    unsigned long _currentMillis;
    unsigned long _previousMillis = 0;
};

class MyTimerButton
{
  
  public:
    MyTimerButton(int pin, long CoolDown);
    void begin();
    void beginPullUp();
    void setSystemMillis(unsigned long SystemMillis);
    bool rising();
    bool falling();
    bool pressed();
    bool released();
    bool toggled();
    uint16_t modeSwitch(uint16_t LowerEnd, uint16_t StartFrom, uint16_t UpperEnd);

  private:
    int _pin = 0;
    unsigned long _CoolDown, _currentMillis;
    bool _PullUpBegun, _Begun = false;
    
    bool pr_blocked, pr_pressed = false; //void pressed
    unsigned long pr_previousMillis = 0;

    bool re_blocked, re_pressed = false; //void release
    unsigned long re_previousMillis = 0;

    bool ri_blocked, ri_pressed = false; //void isPressed
    unsigned long ri_previousMillis = 0;

    bool fa_blocked, fa_pressed = false; //void isRelease
    unsigned long fa_previousMillis = 0;

    bool to_blocked, to_pressed, toggle = false;  //void toggled
    unsigned long to_previousMillis = 0;

    bool mo_blocked, mo_pressed, initalised = false;  //void modeSwitch
    uint16_t _mode, _LowerEnd, _StartFrom, _UpperEnd = 0;
    unsigned long mo_previousMillis = 0;
};

#endif