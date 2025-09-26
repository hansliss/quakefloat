#include "quakefloat.h"

quake_float Q_rsqrt(quake_float number)
{
  // Use a union for bit-level reinterpretion to stay strict-aliasing safe while
  // keeping the original Quake behaviour (treat the float bits as an int and
  // back again). This mirrors the classic pointer-cast hack without invoking
  // undefined behaviour.
  union {
    quake_float f;
    quake_int i;
  } conv;
  const quake_float threehalfs = 1.5F;
  quake_float x2;
  quake_float y;

  x2 = number * 0.5F;
  conv.f = number;
  conv.i = 0x5f3759df - (conv.i >> 1);  // Quake magic constant trick
  y = conv.f;  // Same bits fed back as a float, matching the original cast
  y = y * (threehalfs - (x2 * y * y));

  return y;
}
