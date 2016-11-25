#include <led.h>

// Example for the slacker.led library
// by Patrick Stockton <http://www.naslacker.com>

// Created 11/25/2016

// There's an easier non blocking way to blink the LED

slacker::Led _led(13);

void setup()
{
}

void loop()
{
  _led.Blink(250);
}