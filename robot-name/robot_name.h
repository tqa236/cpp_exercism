#pragma once
#include <string>
#include <vector>

namespace robot_name {
static std::vector<std::string> used_names;
class robot {
 private:
  robot(const robot&);
  robot& operator=(const robot&);
  std::string name_ = "";

 public:
  robot();
  std::string name() const&;
  void reset();
};
}  // namespace robot_name
