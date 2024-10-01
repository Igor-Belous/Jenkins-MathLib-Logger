#include "s21_math.h"

int s21_abs(int val) {
  if (val < 0) val = (val - 1) ^ (-1);
  return val;
}