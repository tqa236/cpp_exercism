#pragma once
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

namespace crypto_square {

class cipher {
 private:
  std::string text;
  std::vector<std::string> segmented_text;
  unsigned int column_length;
  unsigned int row_length;

 public:
  explicit cipher(std::string text);
  std::string normalize_plain_text();
  std::vector<std::string> plain_text_segments();
  std::string cipher_text();
  std::string normalized_cipher_text();
};
}  // namespace crypto_square
