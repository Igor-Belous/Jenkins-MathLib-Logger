#include "all_tests_s21.h"

START_TEST(test_ceil_1) {
  const double testCase[6] = {S21_INF, -S21_INF, NAN, -1.0, -1.0E-16, -500.0};
  int specialVal = check_special_values(s21_sqrt(testCase[_i]));
  int specialValOrigin = check_special_values(sqrtl(testCase[_i]));
  ck_assert_int_eq(specialVal, specialValOrigin);
}
END_TEST

START_TEST(test_ceil_2) {
  const double testCase[13] = {
      1.0,     1.0E-12,           1.0E-13,           M_PI, M_E,       0.0,
      1.0E-16, 1234567890.123456, 9999999999.999999, -0.0, 1000000.0, 1.0E-5,
      0.09};
  ck_assert_ldouble_eq_tol(s21_sqrt(testCase[_i]), sqrtl(testCase[_i]), EPS);
}
END_TEST

Suite *s21_sqrt_suite() {
  Suite *s = suite_create("s21_sqrt");
  TCase *tc = tcase_create("s21_sqrt_tc");

  tcase_add_loop_test(tc, test_ceil_1, 0, 6);
  tcase_add_loop_test(tc, test_ceil_2, 0, 13);

  suite_add_tcase(s, tc);
  return s;
}