#include "all_tests_s21.h"

START_TEST(test_ceil_1) {
  const double testCase[3] = {NAN, S21_INF, -S21_INF};
  ck_assert_ldouble_nan(s21_sin(testCase[_i]));
}
END_TEST

START_TEST(test_ceil_2) {
  const double testCase[15] = {0.0,
                               0.1,
                               -0.1,
                               0.99,
                               -0.99,
                               1.01,
                               -1.01,
                               987654321.0,
                               -987654321.0,
                               0.12345678901234567890,
                               -0.12345678901234567890,
                               1.23456789,
                               -1.23456789,
                               -0.0,
                               -3.0 * M_PI / 2.0};
  ck_assert_ldouble_eq_tol(s21_sin(testCase[_i]), sin(testCase[_i]), EPS);
}
END_TEST

START_TEST(test_ceil_3) {
  int i = _i;
  if (i != 0) {
    ck_assert_ldouble_eq_tol(sin(M_PI / i), s21_sin(M_PI / i), EPS);
  } else {
    ck_assert_ldouble_nan(s21_sin(M_PI / i));
  }
}
END_TEST

START_TEST(test_ceil_4) {
  int i = _i;
  ck_assert_ldouble_eq_tol(sin(M_PI * i), s21_sin(M_PI * i), EPS);
}
END_TEST

Suite *s21_sin_suite() {
  Suite *s = suite_create("s21_sin");
  TCase *tc = tcase_create("s21_sin_tc");

  tcase_add_loop_test(tc, test_ceil_1, 0, 3);
  tcase_add_loop_test(tc, test_ceil_2, 0, 15);
  tcase_add_loop_test(tc, test_ceil_3, -10, 10);
  tcase_add_loop_test(tc, test_ceil_4, -10, 10);

  suite_add_tcase(s, tc);
  return s;
}