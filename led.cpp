/*
  led.cpp - Implementation of an LED controller
  Created by Patrick Stockton
  version: 0.0.3
*/

#include "Arduino.h"
#include "led.h"

namespace slacker 
{
  Led::Led(int pin)
  {
    _previousMillis = 0;
    _ledState = LOW;
    _brightness = 255;
    _pin = pin;
    _blinkCount = 0;
    pinMode(pin, OUTPUT);
  }

  void Led::On()
  {
    if (_brightness == 255)
    {
      digitalWrite(_pin, HIGH);
    }
    else
    {
      analogWrite(_pin, _brightness);
    }
    
    _ledState = HIGH;
  }

  void Led::Off()
  {
    digitalWrite(_pin, LOW);
    _ledState = LOW;
  }

  void Led::SetBrightness(int brightness)
  {
    // I have no idea if this is required or not, but better safe than sorry
    if(brightness < 0)
    {
      brightness = 0;
    }

    if (brightness > 255)
    {
      brightness = 255;
    }

    _brightness = brightness;

    // If the LED is on then we need to change the brightness now
    if (_ledState == HIGH)
    {
      this -> On();
    }
  }

  int Led::GetBrightness()
  {
    return _brightness;
  }

  unsigned long long Led::GetBlinkCount()
  {
    return _blinkCount;
  }

  void Led::ResetBlinkCount()
  {
    _blinkCount = 0;
  }

  void Led::Blink(int blinkRate)
  {
    if(this -> checkMillis(blinkRate))
    {
      if(_ledState == LOW)
      {
        this->On();
      }
      else
      {
        this->Off();
        _blinkCount++;
      }
    }
  }

  bool Led::checkMillis(int millisCheck)
  {
    _blinkRate = millisCheck;
    unsigned long currentMillis = millis();

    if(currentMillis - _previousMillis >= _blinkRate)
    {
      _previousMillis = currentMillis;
      return true;
    }
    else
    {
      return false;
    }
  }

  bool Led::GetState()
  {
    return _ledState;
  }
}