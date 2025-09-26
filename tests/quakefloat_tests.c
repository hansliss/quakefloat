#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "quakefloat.h"

// Expected relative error caps are derived from empirical observations of the
// single-iteration Quake fast inverse square root across many magnitudes. Each
// value is padded slightly above the measured error to allow for rounding
// differences across platforms.
struct test_case {
  quake_float input;
  double max_relative_error;
};

int main(void) {
  const struct test_case cases[] = {
      {1.0e-12f, 3.0e-4},
      {1.0e-9f, 6.0e-4},
      {1.0e-6f, 9.0e-4},
      {1.0e-3f, 1.3e-3},
      {5.0e-1f, 3.0e-4},
      {1.0e0f, 2.0e-3},
      {2.0e0f, 3.0e-4},
      {1.0e1f, 2.0e-3},
      {1.0e3f, 2.0e-3},
      {1.0e6f, 2.0e-3},
      {1.0e9f, 2.0e-3},
      {1.0e12f, 1.0e-3},
  };

  int failures = 0;
  for (size_t idx = 0; idx < sizeof(cases) / sizeof(cases[0]); ++idx) {
    const struct test_case *tc = &cases[idx];
    const quake_float approx = Q_rsqrt(tc->input);
    const double exact = 1.0 / sqrt((double)tc->input);
    const double relative_error = fabs(((double)approx - exact) / exact);

    if (relative_error > tc->max_relative_error) {
      fprintf(stderr,
              "Input %g exceeded expected precision: rel_err=%.6e max=%.6e\n",
              (double)tc->input, relative_error, tc->max_relative_error);
      failures = 1;
    }
  }

  if (failures == 0) {
    puts("All Quake inverse square root precision checks passed.");
  }

  return failures;
}
