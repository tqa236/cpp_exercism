#include <iostream>
#include<cmath>
#include "difference_of_squares.h"

using namespace std;

int squares::square_of_sum(int num){
    // return 225;
    return pow((num * (num+1))/2,2);
  }
int squares::sum_of_squares(int num){
    return num*(num + 1)*(2*num+1)/6;
  }
int squares::difference(int num){
    return squares::square_of_sum(num) - squares::sum_of_squares(num);
  }
