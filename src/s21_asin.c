#include "s21_math.h"

long double s21_asin(double x) {
  int specialVal = check_special_values(x);
  long double res;
  if (specialVal == S21_POS_INF || specialVal == S21_NEG_INF ||
      specialVal == S21_NAN)
    res = NAN;
  else {
    if (x > 1.0 || x < -1.0) {
      res = NAN;
    } else if (s21_fabs(x - 1.0) < PRECISION) {
      res = S21M_PI_2;
    } else if (s21_fabs(x + 1.0) < PRECISION) {
      res = -S21M_PI_2;
    } else if (x * x > 0.6 && x > 0.0) {
      res = s21_acos(s21_sqrt(1.0 - x * x));
    } else if (x * x > 0.6 && x < 0.0) {
      res = -s21_acos(s21_sqrt(1.0 - x * x));
    } else {
      res = x;
      for (double n = 1.0; n < 1000000; n++) {
        long double tmp =
            s21_pow(x, 2.0 * n + 1.0) * factorial(2.0 * n) /
            (s21_pow(factorial(n), 2.0) * s21_pow(4.0, n) * (2.0 * n + 1.0));
        res += tmp;

        if (s21_fabs(tmp) < PRECISION) {
          break;
        }
      }
    }
  }
  return res;
}