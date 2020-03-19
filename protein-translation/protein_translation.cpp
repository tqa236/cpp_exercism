#include "protein_translation.h"
#include <map>

namespace protein_translation {
using std::map;

map<string, string> translator = {
    {"AUG", "Methionine"}, {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
    {"UUA", "Leucine"},    {"UUG", "Leucine"},       {"UCU", "Serine"},
    {"UCC", "Serine"},     {"UCA", "Serine"},        {"UCG", "Serine"},
    {"UAU", "Tyrosine"},   {"UAC", "Tyrosine"},      {"UGU", "Cysteine"},
    {"UGC", "Cysteine"},   {"UGG", "Tryptophan"},    {"UAA", "STOP"},
    {"UAG", "STOP"},       {"UGA", "STOP"}};
vector<string> proteins(string adn) {
  string protein;
  vector<string> protein_names;
  for (auto i = 0; i < (int)adn.length(); i = i + 3) {
    protein = translator[adn.substr(i, 3)];
    if (protein == "STOP") break;
    protein_names.push_back(protein);
  };
  return protein_names;
}

}  // namespace protein_translation
