#include "robot_simulator.h"

namespace robot_simulator {

void Robot::turn_right() {
  {
    switch (robot_bearing) {
      case Bearing::NORTH:
        robot_bearing = Bearing::EAST;
        break;
      case Bearing::EAST:
        robot_bearing = Bearing::SOUTH;
        break;
      case Bearing::SOUTH:
        robot_bearing = Bearing::WEST;
        break;
      case Bearing::WEST:
        robot_bearing = Bearing::NORTH;
        break;
    }
  }
}
void Robot::turn_left() {
  switch (robot_bearing) {
    case Bearing::NORTH:
      robot_bearing = Bearing::WEST;
      break;
    case Bearing::WEST:
      robot_bearing = Bearing::SOUTH;
      break;
    case Bearing::SOUTH:
      robot_bearing = Bearing::EAST;
      break;
    case Bearing::EAST:
      robot_bearing = Bearing::NORTH;
      break;
  }
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
