#include "Arduino.h"
#include "led.h"

Led::Led(int pin)
{
  _previousMillis = 0;
  _ledState = LOW;
  _pin = pin;
  pinMode(pin, OUTPUT);
}

void Led::On()
{
  digitalWrite(_pin, HIGH);
  _ledState = HIGH;
}

void Led::On(int brightness)
{
  if (brightness < 0)
  {
    brightness = 0;
  }
  if (brightness > 255)
  {
    brightness = 255;
  }

  analogWrite(_pin, brightness);
  _ledState = HIGH;
}

void Led::Off()
{
  digitalWrite(_pin, LOW);
  _ledState = LOW;
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
    }
  }
}

void Led::Blink(int blinkRate,int brightness)
{
  if(this -> checkMillis(blinkRate))
  {
    if(_ledState == LOW)
    {
      this->On(brightness);
    }
    else
    {
      this->Off();
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