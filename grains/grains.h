#if !defined(GRAINS_H)
#define GRAINS_H
#include <cstdint>
#include <cmath>

namespace grains {
    using namespace std;
    constexpr uint64_t square(const int number){
        return (uint64_t)1 << (number-1);
    }
    constexpr uint64_t total(){
        return (uint64_t)pow(2, 64) - 1;
    }
}

#endif
