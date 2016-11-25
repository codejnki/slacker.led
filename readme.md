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
On(int brightness)
```

This will turn the Led on using the analog write

```cpp
Off()
```

Three guesses as to what this one does.

```cpp
Blink(int blinkRate);
```

This will blinks the led at the rate in milliseconds you specify.  This blink happens in a non-blocking manner so you can do other things.

```cpp
Blink(int blinkRate, int brightness);
```

Same as the blink method but uses analog write to control the brightness of your LED.  For those times you want a less intense blink.

```cpp
GetState()
```

The LED class tracks the current state of the LED and this simply returns in.  Using either the `On()` or `Off()` methods will change this state.  This is useful if you've lost track of what the state of your LED is.



