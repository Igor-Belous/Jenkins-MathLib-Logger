#include "s21_math.h"

long double s21_atan(double x) {
  int special_value = check_special_values(x);
  long double res;
  if (special_value == S21_POS_INF)
    res = S21M_PI_2;
  else if (special_value == S21_NEG_INF)
    res = -S21M_PI_2;
  else if (special_value == S21_NAN)
    res = NAN;
  else {
    long double signAtan = (x < 0.0) ? -1.0l : 1.0l;
    if (x >= -1.0 && x <= 1.0) {
      res = signAtan * (S21M_PI_2 - s21_asin(1.0l / (s21_sqrt(1.0 + x * x))));
    } else {
      res = signAtan * (S21M_PI_2 - s21_atan(1 / s21_fabs(x)));
    }
  }
  return res;
}