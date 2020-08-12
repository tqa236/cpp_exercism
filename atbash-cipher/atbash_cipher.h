#pragma once
#include <string>

namespace atbash_cipher {
std::string encode(std::string);
std::string decode(std::string);
std::string transform(std::string, bool);
}  // namespace atbash_cipher
