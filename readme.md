# slacker.led

This is a very simple LED library which I wrote to give myself some practice.  It offers up a LED class with some useful functions.

## Installation and useage

To install this library just place the entire folder as a sub folder in your library folder.  You should just be able to clone this repo and begin using right away.

```cpp
#include <led.h>

slacker::Led _led(13);  // let's just use the built in for now

// your awesome code goes here
```

## Methods

```cpp
On()
```

This will turn the Led on.

```cpp
Off()
```

Surprise!  This turns it off.

```cpp
Blink(int blinkRate);
```

This will blinks the led at the rate in milliseconds you specify.  This blink happens in a non-blocking manner so you can do other things.

```cpp
GetState()
```

The LED class tracks the current state of the LED and this simply returns in.  Using either the `On()` or `Off()` methods will change this state.  This is useful if you've lost track of what the state of your LED is.  Using the blink method will also toggle this.

```cpp
SetBrightness(int brightness)
```

Sets the brightness of the led using an anlog out.  The default state of the LED is set to 255 and if it is still 255 a digital out will be used instead.

```cpp
GetBrightness()
```

Returns the current brightness.  Useful if you aren't tracking it yourself.

```cpp
GetBlinkCount()
```

When using the blink function each time the LED turns off a counter is incremented.  This is an unsigned long long, so there's a good chance that the universe will implode before you overrun this.

```cpp
ResetBlinkCount()
```

If you are using the interal blink counter to track things this method will reset the counter to 0.