/*
  Library for controlling a led. 
  Created by Patrick Stockton
  version: 0.0.3
*/

#ifndef led_h
#define led_h

#include "Arduino.h"

namespace slacker
{
  class Led
  {
    public:
      Led(int pin);
      void On();
      void Off();
      void SetBrightness(int brightness);
      int GetBrightness();
      void Blink(int blinkRate);
      unsigned long long GetBlinkCount();
      void ResetBlinkCount();
      bool GetState();

    private:
      bool checkMillis(int millisCheck);
      int _pin;
      int _blinkRate;
      int _ledState;
      int _brightness;
      unsigned long _previousMillis;
      unsigned long long _blinkCount;
  };
}

#endif