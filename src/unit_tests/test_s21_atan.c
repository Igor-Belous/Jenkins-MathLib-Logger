#include "all_tests_s21.h"

START_TEST(test_ceil_1) {
  const double testCase[1] = {NAN};
  ck_assert_ldouble_nan(s21_atan(testCase[_i]));
}
END_TEST

START_TEST(test_ceil_2) {
  const double testCase[16] = {0.0,
                               S21_INF,
                               -S21_INF,
                               9876543219876543.0,
                               -9876543219876543.0,
                               0.12345678901234567890,
                               -0.12345678901234567890,
                               -0.25,
                               -0.5,
                               -0.75 - 0.99,
                               0.25,
                               0.5,
                               0.75,
                               0.99,
                               1.23456789,
                               -1.23456789};
  ck_assert_ldouble_eq_tol(atan(testCase[_i]), s21_atan(testCase[_i]), EPS);
}
END_TEST

START_TEST(test_ceil_3) {
  int i = _i;
  ck_assert_ldouble_eq_tol(atan(i / 30), s21_atan(i / 30), EPS);
}
END_TEST

Suite *s21_atan_suite() {
  Suite *s = suite_create("s21_atan");
  TCase *tc = tcase_create("s21_atan_tc");

  tcase_add_loop_test(tc, test_ceil_1, 0, 1);
  tcase_add_loop_test(tc, test_ceil_2, 0, 16);
  tcase_add_loop_test(tc, test_ceil_3, -10, 10);

  suite_add_tcase(s, tc);
  return s;
}