#include "all_tests_s21.h"

START_TEST(test_ceil_1) {
  const double testCase[7] = {NAN,     S21_INF,       -S21_INF,      5.4321,
                              -5.4321, 1.0 + 1.0E-10, -1.0 - 1.0E-10};
  ck_assert_ldouble_nan(s21_asin(testCase[_i]));
}
END_TEST

START_TEST(test_ceil_2) {
  const double testCase[13] = {0.0,
                               1.0,
                               -1.0,
                               0.12345678901234567890,
                               -0.12345678901234567890,
                               -0.25,
                               0.25,
                               -0.5,
                               0.5,
                               -0.78,
                               0.78,
                               -0.99,
                               0.99};
  ck_assert_ldouble_eq_tol(asin(testCase[_i]), s21_asin(testCase[_i]), EPS);
}
END_TEST

Suite *s21_asin_suite() {
  Suite *s = suite_create("s21_asin");
  TCase *tc = tcase_create("s21_asin_tc");

  tcase_add_loop_test(tc, test_ceil_1, 0, 7);
  tcase_add_loop_test(tc, test_ceil_2, 0, 13);

  suite_add_tcase(s, tc);
  return s;
}