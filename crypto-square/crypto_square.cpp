#include "crypto_square.h"

namespace crypto_square {
string cipher::normalize_plain_text() { return text; }
vector<string> cipher::plain_text_segments() {
  vector<string> encoded_text = {};
  for (unsigned int i = 0; i < text.size(); i = i + column_length) {
    encoded_text.push_back(text.substr(i, column_length));
  }
  return encoded_text;
}
string cipher::cipher_text() {
  string ciphertext = normalized_cipher_text();
  ciphertext.erase(remove_if(ciphertext.begin(), ciphertext.end(),
                             [](char c) { return !isalnum(c); }),
                   ciphertext.end());
  return ciphertext;
}
string cipher::normalized_cipher_text() {
  string normalized_cipher_text_ = "";
  for (unsigned int i = 0; i < column_length; i++) {
    if (i > 0) normalized_cipher_text_.push_back(' ');
    for (auto chunk : segmented_text) {
      if (i < chunk.size()) {
        normalized_cipher_text_.push_back(chunk.at(i));
      } else {
        normalized_cipher_text_.push_back(' ');
      }
    }
  }
  return normalized_cipher_text_;
}
}  // namespace crypto_square
