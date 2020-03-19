#include "robot_name.h"

using std::string;

namespace robot_name {

char robot::random_char() { return (std::rand() % 26) + 'A'; }

char robot::random_digit() { return (std::rand() % 10) + '0'; }

void robot::gen_name() {
  name_.push_back(random_char());
  name_.push_back(random_char());

  name_.push_back(random_digit());
  name_.push_back(random_digit());
  name_.push_back(random_digit());
}

robot::robot() { gen_name(); }

string robot::name() const { return name_; }

void robot::reset() {
  name_.clear();
  gen_name();
}
}  // namespace robot_name
