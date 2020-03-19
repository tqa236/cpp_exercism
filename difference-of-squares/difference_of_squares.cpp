#include "difference_of_squares.h"
#include <cmath>
#include <iostream>

using namespace std;

int difference_of_squares::square_of_sum(int num) {
  return pow((num * (num + 1)) / 2, 2);
}
int difference_of_squares::sum_of_squares(int num) {
  return num * (num + 1) * (2 * num + 1) / 6;
}
int difference_of_squares::difference(int num) {
  return difference_of_squares::square_of_sum(num) -
         difference_of_squares::sum_of_squares(num);
}
