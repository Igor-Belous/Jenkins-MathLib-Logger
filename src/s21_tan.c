#include "s21_math.h"

long double s21_tan(double x) {
  int special_value = check_special_values(x);
  long double res;
  if (special_value == S21_POS_INF || special_value == S21_NEG_INF)
    res = -NAN;
  else if (special_value == S21_NAN)
    res = x;
  else
    res = s21_sin(x) / s21_cos(x);
  return res;
}