#include "all_tests_s21.h"

/*
test_ceil идентификатор теста

testCase массив данных для тестирования типа int, так как данные будут
проверяться макросом ck_assert_int_eq

макрос ck_assert_int_eq принимает 2 переменные типа int для проверки на
равенство
*/

START_TEST(test_ceil) {
  const int testCase[16] = {
      INT_MAX, INT_MIN, 9876543, 123456789, -123456788, 5,  -5,     987654321,
      0,       -1,      1,       -42,       -50,        -6, -99999, 91};
  ck_assert_int_eq(s21_abs(testCase[_i]), -abs(testCase[_i]))
}
END_TEST

Suite *s21_abs_suite() {
  Suite *s = suite_create("s21_abs");
  TCase *tc = tcase_create("s21_abs_tc");

  /*
  макрос tcase_add_loop_test принимает 4 переменные:
  tc название тестируемой функции, в данном кейсе test_ceil: testCase массив
  тестовых данных, 0 индекс начала, 12 размерность массива
  */

  tcase_add_loop_test(tc, test_ceil, 0, 16);
  suite_add_tcase(s, tc);
  return s;
}