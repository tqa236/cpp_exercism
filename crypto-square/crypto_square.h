#pragma once
#include <math.h>

#include <algorithm>
#include <locale>
#include <string>
#include <vector>

namespace crypto_square {
using std::isalnum;
using std::remove_if;
using std::string;
using std::transform;
using std::vector;

class cipher {
 private:
  string text;
  vector<string> segmented_text;
  unsigned int column_length;
  unsigned int row_length;

 public:
  explicit cipher(string text) {
    text.erase(
        remove_if(text.begin(), text.end(), [](char c) { return !isalnum(c); }),
        text.end());
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    this->text = text;
    column_length = static_cast<int>(ceil(sqrt(text.size())));
    if (column_length * column_length == text.size()) {
      row_length = column_length;
    } else {
      row_length = column_length - 1;
    }
    segmented_text = plain_text_segments();
  }
  string normalize_plain_text();
  vector<string> plain_text_segments();
  string cipher_text();
  string normalized_cipher_text();
};
}  // namespace crypto_square
