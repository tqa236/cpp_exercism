#include <string>
#include <map>

using namespace std;

namespace dna {
  class counter{
    public:
      counter(string);
      const std::map<char, int> nucleotide_counts();
  };
}
