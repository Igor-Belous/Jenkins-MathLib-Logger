#include "s21_math.h"

int s21_is_nan(double value) { return value != value; }
int s21_is_inf(double value) { return __builtin_isinf_sign(value); }
int sign(int i) { return (i & 1) ? 1 : -1; }

int64_t abs_int64_t(int64_t value) {
  if (value < 0) value = (value - 1) ^ (-1);
  return value;
}

long double s21_rounding(double value, int type) {
  long double res;
  int special_value = check_special_values(value);
  if (special_value == S21_POS_INF || special_value == S21_NEG_INF ||
      special_value == S21_NAN)
    res = value;
  else {
    double remainder = s21_fmod(value, 1.0);
    res = (int64_t)value;
    if (s21_fabs(remainder) > 0.0l) {
      if (type == S21_CEIL && value > 0) res++;
      if (type == S21_FLOOR && value < 0) res--;
    }
  }
  return res;
}

long double ln_taylor_series(int index, long double value) {
  return sign(index) * value / index;
}

double ln_denominator(int i) { return (double)((i & 1) | 1); }

long double exp_taylor_series(int index, long double value) {
  (void)index;
  return value;
}

double exp_denominator(int i) { return (double)i; }

int ln_exponent_offset(double *value) {
  int i = 0;
  if (*value > 1) {
    while (*value > 1) {
      *value /= 10;
      i++;
    }
  } else if (*value < 0.1) {
    while (*value < 0.1) {
      *value *= 10;
      i--;
    }
  }
  return i;
}

long double taylor_main_function(double value,
                                 long double function(int, long double),
                                 double denom(int)) {
  long double x = 0.0l;
  long double powValue = 1.0l;
  bool flag = true;
  for (int i = 1; flag; i++) {
    powValue *= value / denom(i);
    long double nx = function(i, powValue);
    x += nx;
    if (s21_fabs(nx) < PRECISION) flag = false;
  }
  return x;
}

long double exp_by_squaring(double base, int64_t exp) {
  long double res = 1.0l;
  if (exp == 0)
    base = res;
  else if (exp < 0) {
    base = 1.0 / base;
    exp = abs_int64_t(exp);
  }
  while (exp > 1) {
    if (exp % 2) {
      res *= base;
      exp -= 1;
    }
    base *= base;
    exp = exp >> 1;
  }
  return res * base;
}

int check_special_values(double value) {
  int flag = 1;
  if (value == value) {
    if (s21_is_inf(value)) {
      if (value > 0.0)
        flag = S21_POS_INF;
      else
        flag = S21_NEG_INF;
    }
  } else
    flag = S21_NAN;
  return flag;
}

long double factorial(int n) {
  long double res = 1.0l;

  for (long double i = 1.0l; i <= n; i++) {
    res *= i;
  }

  return res;
}

long double infinity_pow(double value, int special_value) {
  long double res;
  long double tmp = s21_fabs(value);
  if (tmp == 1.0)
    res = tmp;
  else if (0.0l <= tmp && tmp < 1.0l)
    res = (special_value == S21_POS_INF) ? 0.0 : S21_INF;
  else
    res = (special_value == S21_POS_INF) ? S21_INF : 0.0l;
  return res;
}