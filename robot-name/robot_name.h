#pragma once
#include <string>
#include <vector>

namespace robot_name {
using std::string;
using std::vector;
class robot {
 private:
  string name_ = "";
  char random_char();
  char random_digit();
  void gen_name();

 public:
  robot();
  string name() const&;
  void reset();
};
}  // namespace robot_name
