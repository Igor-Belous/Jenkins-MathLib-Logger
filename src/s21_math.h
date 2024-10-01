#ifndef __S21_FUNC__
#define __S21_FUNC__

#define _POSIX_C_SOURCE 200809L
#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>

#define S21_M_PI 3.14159265358979323846
#define S21M_PI_2 1.57079632679489661923132169163975144
#define PRECISION 1.0E-10L
#define LOG10 2.302585092994045684017991454684364208L
#define EXP_OVERFLOW_MAX 7.097827E+002
#define EXP_OVERFLOW_MIN -7.083964E+002

#ifndef NAN
#define NAN (__builtin_nanf(""))
#endif
#define S21_INF (1.0l / 0.0l)
#define S21_POS_INF 1 << 1
#define S21_NEG_INF 1 << 2
#define S21_NAN 1 << 3
#define S21_CEIL 1 << 1
#define S21_FLOOR 1 << 2

long double factorial(int n);
int s21_is_nan(double value);
int s21_is_inf(double value);
int sign(int i);
int check_special_values(double value);
long double s21_rounding(double value, int type);
int s21_abs(int value);
int64_t abs_int64_t(int64_t value);
long double s21_ceil(double value);
long double s21_exp(double x);
long double s21_fabs(double value);
long double s21_floor(double value);
long double s21_fmod(double x, double y);
long double ln_taylor_series(int index, long double value);
double ln_denominator(int i);
long double exp_taylor_series(int index, long double value);
double exp_denominator(int i);
int ln_exponent_offset(double *value);
long double taylor_main_function(double value,
                                 long double function(int, long double),
                                 double denom(int));
long double s21_log(double value);
long double exp_by_squaring(double base, int64_t exp);
long double infinity_pow(double value, int specialVal);
long double s21_pow(double base, double exp);
long double s21_sqrt(double value);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);

#endif