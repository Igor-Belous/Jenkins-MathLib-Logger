#include "s21_math.h"

long double s21_fmod(double x, double y) {
  int x_special_value = check_special_values(x);
  int y_special_value = check_special_values(y);
  long double res;
  if (x_special_value == S21_NAN || y_special_value == S21_NAN)
    res = NAN;
  else if (x_special_value == S21_POS_INF || x_special_value == S21_NEG_INF)
    res = -NAN;
  else if (y_special_value == S21_POS_INF || y_special_value == S21_NEG_INF)
    res = x;
  else {
    if (y == 0.0)
      res = -NAN;
    else {
      long double intPart = (int64_t)(x / y);
      res = (long double)x - intPart * (long double)y;
    }
  }
  return res;
}