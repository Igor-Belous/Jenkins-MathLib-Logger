#include "s21_math.h"

long double s21_sqrt(double value) {
  int special_value = check_special_values(value);
  long double res;
  if (special_value == S21_POS_INF || special_value == S21_NAN)
    res = value;
  else {
    if (value >= 0.0) {
      double x = 1.0;
      bool flag = true;
      while (flag) {
        double nx = (x + value / x) / 2.0;
        if (s21_fabs(x - nx) < PRECISION) {
          res = x;
          flag = false;
        }
        x = nx;
      }
    } else
      res = -NAN;
  }
  return res;
}