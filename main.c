#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "quakefloat.h"

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    quake_float val = strtof(argv[i], NULL);
    double exact = 1.0 / sqrt((double)val);
    quake_float approx = Q_rsqrt(val);
    printf("1/sqrt(%f) = %f and %f\n", (double)val, exact, (double)approx);
  }
  return 0;
}
