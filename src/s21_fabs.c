#include "s21_math.h"

long double s21_fabs(double value) {
  long double res;
  if (s21_is_nan(value))
    res = NAN;
  else {
    if (value < 0.0)
      res = -value;
    else
      res = value;
  }
  return res;
}