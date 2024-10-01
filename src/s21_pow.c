#include "s21_math.h"

long double s21_pow(double base, double exp) {
  int base_special_value = check_special_values(base);
  int exp_special_value = check_special_values(exp);
  long double res;
  if (exp == 0.0)
    res = 1.0l;
  else if (exp_special_value == S21_NAN || base_special_value == S21_NAN)
    res = NAN;
  else if (exp == 1.0)
    res = base;
  else if (exp_special_value == S21_NEG_INF) {
    if (base_special_value == S21_POS_INF)
      res = 0.0l;
    else
      res = infinity_pow(base, exp_special_value);
  } else if (exp_special_value == S21_POS_INF) {
    if (base_special_value == S21_NEG_INF)
      res = S21_INF;
    else
      res = infinity_pow(base, exp_special_value);
  } else if (base_special_value == S21_NEG_INF) {
    if (exp < 0.0)
      res = 0.0l;
    else
      res = S21_INF;
  } else if (base_special_value == S21_POS_INF) {
    if (exp > 0.0)
      res = base;
    else
      res = 0.0l;
  } else {
    double expInt = s21_fmod(exp, 1.0);
    res = exp_by_squaring(base, (int64_t)exp);
    if (s21_fabs(expInt) > 0.0l) res *= s21_exp(expInt * s21_log(base));
  }
  return res;
}