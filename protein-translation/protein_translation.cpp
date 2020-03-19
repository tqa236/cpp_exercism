#include "protein_translation.h"
#include <map>

namespace protein_translation {
using std::map;

map<string, string> translator = {{"AUG", "Methionine"}};
vector<string> proteins(string adn) { return vector<string>{translator[adn]}; }

}  // namespace protein_translation
