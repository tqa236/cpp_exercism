#include "robot_name.h"
#include <algorithm>
#include <random>

namespace robot_name {

char random_char() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, 25);
  return (distrib(gen) % 26) + 'A';
}
char random_digit() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, 9);
  return (distrib(gen) % 10) + '0';
}

std::string gen_name() {
  std::string name_ = "";
  name_.push_back(robot_name::random_char());
  name_.push_back(robot_name::random_char());

  name_.push_back(robot_name::random_digit());
  name_.push_back(robot_name::random_digit());
  name_.push_back(robot_name::random_digit());
  return name_;
}

robot::robot() { reset(); }

std::string robot::name() const& { return name_; }

void robot::reset() {
  std::string old_name = name_;
  while (old_name == name_ || std::find(used_names.begin(), used_names.end(),
                                        name_) != used_names.end()) {
    name_ = robot_name::gen_name();
  }
  used_names.push_back(name_);
}
}  // namespace robot_name
