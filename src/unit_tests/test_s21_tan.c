#include "all_tests_s21.h"

/*
test_ceil_1 идентификатор теста

testCase массив данных для тестирования типа double, так как данные будут
проверяться макросом ck_assert_ldouble_nan и ck_assert_ldouble_eq_tol

макрос ck_assert_ldouble_nan принимает переменную типа long double для проверки
на специальное значение NAN и INF

макрос ck_assert_ldouble_eq_tol проверяет, что значение переменных (функций) не
превосходит EPS
*/

START_TEST(test_ceil_1) {
  const double testCase[3] = {NAN, S21_INF, -S21_INF};
  ck_assert_ldouble_nan(s21_tan(testCase[_i]));
}
END_TEST

START_TEST(test_ceil_2) {
  const double testCase[11] = {0.0,
                               181.0 * M_PI / 180.0,
                               11.0 * M_PI / 10.0,
                               5.0 * M_PI / 4.0,
                               23.0 * M_PI / 12.0,
                               0.123456789012345,
                               -0.123456789012345,
                               1.23456789,
                               -1.23456789,
                               -1.0,
                               -100.0};
  ck_assert_ldouble_eq_tol(s21_tan(testCase[_i]), tan(testCase[_i]), EPS);
}
END_TEST

START_TEST(test_ceil_3) {
  int i = _i;
  if (i == 0)
    ck_assert_ldouble_nan(s21_tan(M_PI / i));
  else if (!(i == 2 || i == -2))
    ck_assert_ldouble_eq_tol(tan(M_PI / i), s21_tan(M_PI / i), EPS);
}
END_TEST

START_TEST(test_ceil_4) {
  int i = _i;
  ck_assert_ldouble_eq_tol(tan(M_PI * i), s21_tan(M_PI * i), EPS);
}
END_TEST

Suite *s21_tan_suite() {
  Suite *s = suite_create("s21_tan");
  TCase *tc = tcase_create("s21_tan_tc");

  /*
  макрос tcase_add_loop_test принимает 4 переменные:
  tc название тестируемой функции, в кейсах test_ceil_1 и test_ceil_2:
  итерируется массив testCase, s индекс начала, e размерность массива
  testCase

  в кейсах test_ceil_3 и test_ceil_4 значения индекса меняются в заданном
  диапазоне
  */

  tcase_add_loop_test(tc, test_ceil_1, 0, 3);
  tcase_add_loop_test(tc, test_ceil_2, 0, 11);
  tcase_add_loop_test(tc, test_ceil_3, -10, 10);
  tcase_add_loop_test(tc, test_ceil_4, -10, 10);

  suite_add_tcase(s, tc);
  return s;
}