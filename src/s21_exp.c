#include "s21_math.h"

long double s21_exp(double value) {
  int special_value = check_special_values(value);
  long double res;
  if (special_value == S21_POS_INF || special_value == S21_NAN)
    res = value;
  else if (special_value == S21_NEG_INF)
    res = 0.0L;
  else {
    if (value > EXP_OVERFLOW_MAX)
      res = S21_INF;
    else if (value <= EXP_OVERFLOW_MIN)
      res = 0.0L;
    else {
      long double tmp =
          1.0L + taylor_main_function(s21_fabs(value), exp_taylor_series,
                                      exp_denominator);
      if (value < 0.0)
        res = 1.0L / tmp;
      else
        res = tmp;
    }
  }
  return res;
}