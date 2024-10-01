#include "s21_math.h"

long double s21_acos(double x) { return (long double)S21M_PI_2 - s21_asin(x); }