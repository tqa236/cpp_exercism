#include <map>
#include <string>

using namespace std;

namespace dna {
class counter {
 private:
  string dna_string;

 public:
  counter(const string &a_dna) {
    if (a_dna.find_first_not_of("ACTG") != string::npos) {
      throw std::invalid_argument("It must only contain letters 'ACTG'");
    }
    dna_string = a_dna;
  };
  map<char, int> nucleotide_counts() const;
  int count(char) const;
};
}  // namespace dna
