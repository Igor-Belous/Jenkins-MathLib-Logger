#include "all_tests_s21.h"

START_TEST(test_ceil_1) {
  const double testCase[4] = {S21_INF, -S21_INF, NAN, -NAN};
  int specialVal = check_special_values(s21_floor(testCase[_i]));
  int specialValOrigin = check_special_values(floorl(testCase[_i]));
  ck_assert_int_eq(specialVal, specialValOrigin);
}
END_TEST

START_TEST(test_ceil_2) {
  const double testCase[16] = {1.0,
                               -1.0,
                               0.5,
                               -0.5,
                               0.0,
                               -0.0,
                               1.0E-16,
                               -1.0E-16,
                               1234567890.123456,
                               -1234567890.123456,
                               9999999999.999999,
                               -9999999999.999999,
                               0.9999999,
                               1234.000009,
                               -999.99,
                               1.0E-6};
  ck_assert_ldouble_eq_tol(s21_floor(testCase[_i]), floorl(testCase[_i]), EPS);
}
END_TEST

Suite *s21_floor_suite() {
  Suite *s = suite_create("s21_floor");
  TCase *tc = tcase_create("s21_floor_tc");

  tcase_add_loop_test(tc, test_ceil_1, 0, 4);
  tcase_add_loop_test(tc, test_ceil_2, 0, 16);

  suite_add_tcase(s, tc);
  return s;
}