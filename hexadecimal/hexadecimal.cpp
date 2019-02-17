#include "hexadecimal.h"

using std::string;

namespace hexadecimal {
int convert(string hex) {
  int dec = 0;
  int l = hex.length();
  for (int i = 0; i < l; i++) {
    int num = static_cast<int>(hex[i]);
    if ((num >= 48) && (num <= 57)) {
      num = num - static_cast<int>('0');
    } else {
      if ((num >= 97) && (num <= 102)) {
        num = num - static_cast<int>('a') + 10;
      } else {
        return 0;
      }
    }
    dec = 16 * dec + num;
  }
  return dec;
}
}  // namespace hexadecimal
