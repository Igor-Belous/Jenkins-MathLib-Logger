#include "all_tests_s21.h"

START_TEST(test_case_1) {
  double x = NAN;
  ck_assert_ldouble_nan(s21_fabs(x));
}
END_TEST

START_TEST(test_ceil_1) {
  const double testCase[2] = {S21_INF, -S21_INF};
  ck_assert_ldouble_infinite(s21_fabs(testCase[_i]));
}
END_TEST

START_TEST(test_ceil_2) {
  const double testCase[12] = {9876543.0,    123456789.0, 1.0E16,      -1.0E16,
                               -123456788.0, 5.0,         987654321.0, -1.E-4,
                               -10000000,    -0.00000009, -456789.0,   0.0};
  ck_assert_ldouble_eq_tol(s21_fabs(testCase[_i]), fabs(testCase[_i]), EPS);
}
END_TEST

Suite *s21_fabs_suite() {
  Suite *s = suite_create("s21_fabs");
  TCase *tc = tcase_create("s21_fabs_tc");

  tcase_add_test(tc, test_case_1);
  tcase_add_loop_test(tc, test_ceil_1, 0, 2);
  tcase_add_loop_test(tc, test_ceil_2, 0, 12);
  suite_add_tcase(s, tc);
  return s;
}