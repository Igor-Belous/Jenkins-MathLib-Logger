#include "all_tests_s21.h"

START_TEST(test_ceil) {
  const double testCase[88][2] = {{123456789, 0.123457},
                                  {123456789, -0.123457},
                                  {0.0, 0.0},
                                  {1.2, -1.2},
                                  {1.2, 1.2},
                                  {1.0E6, 2.0},
                                  {1.0E6, -1.0},
                                  {2.3, 5.0},
                                  {2.3, 5.123},
                                  {2.0, 3.0},
                                  {-2.0, 3.0},
                                  {2.0, -3.0},
                                  {-2.0, -3.0},
                                  {1.5, 2.0},
                                  {1.5, -2.0},
                                  {-1.5, -2.0},
                                  {-1.5, 2.0},
                                  {25.0, 0.333333},
                                  {3.0, -2.0},
                                  {4.0, -0.5},
                                  {0.0, 5.0},
                                  {5.0, 0.0},
                                  {1.2345678901234567, 3.0},
                                  {2.0, 30.0},
                                  {1.0E-16, 2.0},
                                  {1.0, -5.0},
                                  {1.2345678901234567, 3.0},
                                  {25.0, 0.333333},
                                  {5.8, 0.0},
                                  {0.0, 0.0},
                                  {789.789, -1.0},
                                  {789.789, 1.0},
                                  {NAN, 0.0},
                                  {S21_INF, -S21_INF},
                                  {S21_INF, 0.0},
                                  {S21_INF, -1.0},
                                  {S21_INF, -EPS},
                                  {NAN, NAN},
                                  {NAN, S21_INF},
                                  {NAN, -S21_INF},
                                  {NAN, 1.0},
                                  {NAN, -1.0},
                                  {S21_INF, NAN},
                                  {S21_INF, S21_INF},
                                  {S21_INF, 1.0},
                                  {S21_INF, EPS},
                                  {S21_INF, 0.5},
                                  {S21_INF, -0.5},
                                  {S21_INF, 2.0},
                                  {S21_INF, -2.0},
                                  {-S21_INF, NAN},
                                  {-S21_INF, S21_INF},
                                  {-S21_INF, -S21_INF},
                                  {-S21_INF, 0.0},
                                  {-S21_INF, 1.0},
                                  {-S21_INF, -1.0},
                                  {-S21_INF, EPS},
                                  {-S21_INF, 0.5},
                                  {-S21_INF, -0.5},
                                  {-S21_INF, 2.0},
                                  {-S21_INF, -2.0},
                                  {0.0, NAN},
                                  {0.0, S21_INF},
                                  {0.0, -S21_INF},
                                  {EPS, S21_INF},
                                  {EPS, -S21_INF},
                                  {-EPS, S21_INF},
                                  {-EPS, -S21_INF},
                                  {0.999999, S21_INF},
                                  {0.999999, -S21_INF},
                                  {-0.999999, S21_INF},
                                  {-0.999999, -S21_INF},
                                  {1.0, S21_INF},
                                  {1.0, -S21_INF},
                                  {-1.0, S21_INF},
                                  {-1.0, -S21_INF},
                                  {1.000001, S21_INF},
                                  {1.000001, -S21_INF},
                                  {-1.000001, -S21_INF},
                                  {-1.000001, S21_INF},
                                  {-2.0, S21_INF},
                                  {-2.0, -S21_INF},
                                  {2.0, S21_INF},
                                  {2.0, -S21_INF},
                                  {15.0, 15.0},
                                  {0.01, 0.01},
                                  {9.99999, 1.234},
                                  {10.0, 10.0}};
  int specialVal =
      check_special_values(s21_pow(testCase[_i][0], testCase[_i][1]));
  if (specialVal == S21_POS_INF || specialVal == S21_NEG_INF ||
      specialVal == S21_NAN) {
    int specialValOrigin =
        check_special_values(powl(testCase[_i][0], testCase[_i][1]));
    ck_assert_int_eq(specialVal, specialValOrigin);
  } else
    ck_assert_ldouble_eq_tol(s21_pow(testCase[_i][0], testCase[_i][1]),
                             powl(testCase[_i][0], testCase[_i][1]), EPS);
}
END_TEST

Suite *s21_pow_suite() {
  Suite *s = suite_create("s21_pow");
  TCase *tc = tcase_create("s21_pow_tc");

  tcase_add_loop_test(tc, test_ceil, 0, 88);

  suite_add_tcase(s, tc);
  return s;
}