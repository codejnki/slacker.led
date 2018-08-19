/*
  SOS example
  Uses the LED built in counter to signal SOS
  Created by Patrick Stockton
  version: 0.0.1
*/

#include <led.hpp>

slacker::Led _led(13);

void setup()
{}

void loop()
{
  if(_led.GetBlinkCount() < 3)
  {
    _led.Blink(200);
  }
  else if (_led.GetBlinkCount() < 6)
  {
    _led.Blink(400);
  }
  else if (_led.GetBlinkCount() < 9)
  {
    _led.Blink(200);
  }
  else
  {
    delay(1000);
    _led.ResetBlinkCount();
  }
}