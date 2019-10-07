#include "robot_simulator.h"

namespace robot_simulator {

void Robot::turn_right() {
  robot_bearing = robot_bearing == Bearing::WEST
                      ? Bearing::NORTH
                      : static_cast<Bearing>(robot_bearing + 1);
}
void Robot::turn_left() {
  robot_bearing = robot_bearing == Bearing::NORTH
                      ? Bearing::WEST
                      : static_cast<Bearing>(robot_bearing - 1);
}
void Robot::advance() {
  switch (robot_bearing) {
    case Bearing::NORTH:
      robot_position.second = robot_position.second + 1;
      break;
    case Bearing::EAST:
      robot_position.first = robot_position.first + 1;
      break;
    case Bearing::SOUTH:
      robot_position.second = robot_position.second - 1;
      break;
    case Bearing::WEST:
      robot_position.first = robot_position.first - 1;
      break;
  }
}

void Robot::execute_sequence(string sequence) {
  for (char& action : sequence) {
    switch (action) {
      case 'R':
        turn_right();
        break;
      case 'L':
        turn_left();
        break;
      case 'A':
        advance();
        break;
    }
  }
  if (sequence == "R") {
    turn_right();
  }
}

}  // namespace robot_simulator
