/*
  Led.h - Library for controlling a led. 
  Created by Patrick Stockton
  version: 0.0.2
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
      void On(int brightness);
      void Off();
      void Blink(int blinkRate);
      void Blink(int blinkRate, int brightness);
      bool GetState();

    private:
      bool checkMillis(int millisCheck);
      int _pin;
      int _blinkRate;
      int _ledState;
      unsigned long _previousMillis;
  };
}

#endif