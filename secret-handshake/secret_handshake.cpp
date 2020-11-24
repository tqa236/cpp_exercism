#include "secret_handshake.h"

#include <algorithm>

std::vector<std::string> secret_handshake::commands(int code) {
  const std::vector<std::string> actions{"wink", "double blink",
                                         "close your eyes", "jump"};
  std::vector<std::string> selected_actions;
  for (long unsigned int i = 0; i != actions.size(); i++) {
    if ((code & 1 << i) > 0) selected_actions.push_back(actions[i]);
  }
  if (code > 16) std::reverse(selected_actions.begin(), selected_actions.end());
  return selected_actions;
}
