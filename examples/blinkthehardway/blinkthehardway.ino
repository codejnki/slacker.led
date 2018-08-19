#include <led.hpp>

// Example for the slacker.led library
// by Patrick Stockton <http://www.naslacker.com>

// Created 11/24/2016

// This example shows how to do blinking the hard way with the slacker.led library

// create a new instance of a led
slacker::Led _led(13);

void setup()
{
}

void loop()
{
  _led.On();
  delay(500);
  _led.Off();
  delay(500);
}