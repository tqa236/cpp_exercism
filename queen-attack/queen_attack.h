#pragma once
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include <utility>

namespace queen_attack {
using std::domain_error;
using std::make_pair;
using std::pair;
using std::string;

class chess_board {
 private:
  pair<int, int> white_position;
  pair<int, int> black_position;
  unsigned get_queen_position_in_string(pair<int, int> coordinates) const;

 public:
  chess_board() {
    white_position = make_pair(0, 3);
    black_position = make_pair(7, 3);
  }
  chess_board(pair<int, int> white, pair<int, int> black) {
    white_position = white;
    black_position = black;
    if (white_position == black_position) {
      throw domain_error("Queen positions must be distinct.");
    }
  }
  pair<int, int> white() const;
  pair<int, int> black() const;
  bool can_attack() const;
  operator string() const;
};

}  // namespace queen_attack
