#include <iostream>
#include "trinary.h"

int trinary::to_decimal(string tri_num){
  int dec_num = 0;
  for(char c : tri_num) {
    if ((c < '0') || (c > '2')){
      return 0;
    }
    dec_num = (c - '0') + 3 * dec_num;
}
  return dec_num;
}
