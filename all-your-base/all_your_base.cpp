#include "all_your_base.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace all_your_base {
vector<unsigned int> convert(int in_base, vector<unsigned int> in_digits,
                             int out_base) {
  int dec_num = to_dec(in_base, in_digits);
  vector<unsigned int> out_digits = to_base(dec_num, out_base);
  return out_digits;
}

int to_dec(int in_base, vector<unsigned int> in_digits) {
  if (in_digits.size() == 0) return 0;
  if (in_digits.front() == 0) return 0;
  if (*max_element(begin(in_digits), end(in_digits)) >= (unsigned)in_base) {
    return 0;
  }
  int dec_num = 0;
  for (auto const &digit : in_digits) {
    dec_num = digit + in_base * dec_num;
  }
  return dec_num;
}

vector<unsigned int> to_base(int dec_num, int out_base) {
  vector<unsigned int> out_digits;
  if (out_base < 2) return out_digits;
  while (dec_num != 0) {
    out_digits.insert(out_digits.begin(), dec_num % out_base);
    dec_num = dec_num / out_base;
  }
  return out_digits;
}
}  // namespace all_your_base
