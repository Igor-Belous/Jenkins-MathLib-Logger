#include "all_tests_s21.h"

START_TEST(test_ceil_1) {
  const double testCase[8] = {S21_INF, -S21_INF, NAN,  -1.0E-16,
                              0.0,     -0.0,     -1.0, -10.0};
  int specialVal = check_special_values(s21_log(testCase[_i]));
  int specialValOrigin = check_special_values(logl(testCase[_i]));
  ck_assert_int_eq(specialVal, specialValOrigin);
}
END_TEST

START_TEST(test_ceil_2) {
  const double testCase[11] = {1.0,
                               1.0E-16,
                               1.0E-6,
                               0.999999,
                               2.0,
                               1234567890.123456,
                               9999999999.999999,
                               M_PI,
                               M_E,
                               10.0,
                               1.0};
  ck_assert_ldouble_eq_tol(s21_log(testCase[_i]), logl(testCase[_i]), EPS);
}
END_TEST

Suite *s21_log_suite() {
  Suite *s = suite_create("s21_log");
  TCase *tc = tcase_create("s21_log_tc");

  tcase_add_loop_test(tc, test_ceil_1, 0, 8);
  tcase_add_loop_test(tc, test_ceil_2, 0, 11);

  suite_add_tcase(s, tc);
  return s;
}