#include "all_tests_s21.h"

START_TEST(test_ceil_1) {
  const double testCase[] = {NAN, S21_INF};
  ck_assert_ldouble_nan(s21_cos(testCase[_i]));
}
END_TEST

START_TEST(test_ceil_2) {
  const double testCase[7] = {0.0,
                              987654321.0,
                              -987654321.0,
                              0.12345678901234567890,
                              -0.12345678901234567890,
                              1.23456789,
                              -1.23456789};
  ck_assert_ldouble_eq_tol(s21_cos(testCase[_i]), cos(testCase[_i]), EPS);
}
END_TEST

START_TEST(test_ceil_3) {
  int i = _i;
  if (i != 0) {
    ck_assert_ldouble_eq_tol(cos(M_PI / i), s21_cos(M_PI / i), EPS);
  } else {
    ck_assert_ldouble_nan(s21_cos(M_PI / i));
  }
}
END_TEST

START_TEST(test_ceil_4) {
  int i = _i;
  ck_assert_ldouble_eq_tol(cos(M_PI * i), s21_cos(M_PI * i), EPS);
}
END_TEST

Suite *s21_cos_suite() {
  Suite *s = suite_create("s21_cos");
  TCase *tc = tcase_create("s21_cos_tc");

  tcase_add_loop_test(tc, test_ceil_1, 0, 2);
  tcase_add_loop_test(tc, test_ceil_2, 0, 7);
  tcase_add_loop_test(tc, test_ceil_3, -10, 10);
  tcase_add_loop_test(tc, test_ceil_4, -10, 10);

  suite_add_tcase(s, tc);
  return s;
}