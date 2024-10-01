#include "all_tests_s21.h"

START_TEST(test_ceil_1) {
  const double testCase[3] = {S21_INF, NAN, EXP_OVERFLOW_MAX + 1.0E-4};
  int specialVal = check_special_values(s21_exp(testCase[_i]));
  int specialValOrigin = check_special_values(exp(testCase[_i]));
  ck_assert_int_eq(specialVal, specialValOrigin);
}
END_TEST

START_TEST(test_ceil_2) {
  const double testCase[15] = {-S21_INF,  EXP_OVERFLOW_MIN,
                               1.0E-16,   -1.0E-16,
                               1.0E-6,    -1.0E-6,
                               1.0,       -1.0,
                               0.0,       21.0,
                               M_E,       M_PI,
                               0.12345,   1.0,
                               -1000000.0};
  ck_assert_ldouble_eq_tol(s21_exp(testCase[_i]), exp(testCase[_i]), EPS);
}
END_TEST

Suite *s21_exp_suite() {
  Suite *s = suite_create("s21_exp");
  TCase *tc = tcase_create("s21_exp_tc");

  tcase_add_loop_test(tc, test_ceil_1, 0, 3);
  tcase_add_loop_test(tc, test_ceil_2, 0, 15);

  suite_add_tcase(s, tc);
  return s;
}