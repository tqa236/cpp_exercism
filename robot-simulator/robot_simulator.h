#pragma once
#include <string>
#include <utility>

namespace robot_simulator {
using std::pair;
using std::string;
enum Bearing { NORTH, EAST, SOUTH, WEST };
class Robot {
 private:
  pair<int, int> robot_position;
  Bearing robot_bearing;

 public:
  Robot() {
    robot_position = pair<int, int>(0, 0);
    robot_bearing = Bearing::NORTH;
  }
  Robot(pair<int, int> robot_position, Bearing robot_bearing) {
    this->robot_position = robot_position;
    this->robot_bearing = robot_bearing;
  }
  pair<int, int> get_position() const { return robot_position; }
  Bearing get_bearing() const { return robot_bearing; }
  void turn_right();
  void turn_left();
  void advance();
  void execute_sequence(string);
};

}  // namespace robot_simulator
