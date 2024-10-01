#include "s21_math.h"

long double s21_log(double value) {
  int special_value = check_special_values(value);
  long double res;
  if (special_value == S21_POS_INF || special_value == S21_NAN)
    res = value;
  else if (special_value == S21_NEG_INF)
    res = NAN;
  else {
    if (value < 0.0)
      res = NAN;
    else if (value == 0.0)
      res = -S21_INF;
    else {
      int offset = ln_exponent_offset(&value);
      if (!offset)
        res =
            taylor_main_function(value - 1.0, ln_taylor_series, ln_denominator);
      else
        res = taylor_main_function(value - 1.0, ln_taylor_series,
                                   ln_denominator) +
              offset * LOG10;
    }
  }
  return res;
}