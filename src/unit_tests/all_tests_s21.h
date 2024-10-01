#ifndef ALL_TESTS_S21
#define ALL_TESTS_S21

#include <stdio.h>
#include <stdlib.h>

#ifdef __gnu_linux__
#ifndef __USE_MISC
#define __USE_MISC
#endif
#endif
#include <check.h>

#include "../s21_math.h"

#define EPS 1.0E-6L

Suite *s21_abs_suite(void);
Suite *s21_fmod_suite(void);
Suite *s21_ceil_suite(void);
Suite *s21_floor_suite(void);
Suite *s21_sin_suite(void);
Suite *s21_cos_suite(void);
Suite *s21_asin_suite(void);
Suite *s21_acos_suite(void);
Suite *s21_atan_suite(void);
Suite *s21_tan_suite(void);
Suite *s21_exp_suite(void);
Suite *s21_log_suite(void);
Suite *s21_pow_suite(void);
Suite *s21_sqrt_suite(void);
Suite *s21_fabs_suite(void);

void make_the_test(Suite *test_to_run, int *tests_counter);

#endif