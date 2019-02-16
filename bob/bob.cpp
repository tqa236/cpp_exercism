#include "bob.h"
#include <locale>

using namespace std;

string bob::hey(string text) {
  bool no_lowercase = true;
  bool has_uppercase = false;
  bool is_question = false;
  bool is_empty = true;
  for (char &c : text) {
    if (c != ' ') {
      is_question = false;
      is_empty = false;
    }
    if ((c >= 'a') && (c <= 'z')) {
      no_lowercase = false;
    }
    if ((c >= 'A') && (c <= 'Z')) {
      has_uppercase = true;
    }
    if (c == '?') {
      is_question = true;
    }
  }
  if (is_empty) {
    return "Fine. Be that way!";
  }
  if (no_lowercase && has_uppercase) {
    return "Whoa, chill out!";
  }
  if (is_question) {
    return "Sure.";
  }
  return "Whatever.";
}
