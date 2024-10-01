#include "s21_math.h"

long double s21_cos(double x) {
  int special_value = check_special_values(x);
  long double res;
  if (special_value == S21_POS_INF || special_value == S21_NEG_INF)
    res = -NAN;
  else if (special_value == S21_NAN)
    res = x;
  else {
    long double new_x = x;
    new_x = s21_fmod(new_x, 2.0 * S21_M_PI);
    res = 1.0L;
    long double tmp = 1.0L;
    long double x_square = new_x * new_x;
    long double sign = -1.0L;
    for (long double i = 2.0L; i < 10000.0L; i += 2.0L) {
      tmp *= x_square / (i * (i - 1.0L));
      res += sign * tmp;
      if (tmp < PRECISION) break;
      sign *= (-1.0L);
    }
  }
  return res;
}