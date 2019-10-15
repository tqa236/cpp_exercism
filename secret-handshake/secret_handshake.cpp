#include "secret_handshake.h"
#include <algorithm>

namespace secret_handshake {
using std::reverse;

vector<string> actions{"wink", "double blink", "close your eyes", "jump"};
vector<string> commands(int code) {
  vector<string> selected_actions;
  for (long unsigned int i = 0; i != actions.size(); i++) {
    if ((code & 1 << i) > 0) selected_actions.push_back(actions[i]);
  }
  if (code > 16) reverse(selected_actions.begin(), selected_actions.end());
  return selected_actions;
}
}  // namespace secret_handshake
