#pragma once
#include <string>

namespace date_independent {
using std::string;

class clock {
 private:
  int hour;
  int minute;

 public:
  static clock at(int, int);
  operator std::string() const;
};
}  // namespace date_independent
