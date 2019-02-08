#include "grains.h"
#include <cmath>

using namespace std;

uint64_t grains::square(const int number){
    return (uint64_t)1 << (number-1);
}

uint64_t grains::total(){
    return (uint64_t)pow(2, 64) - 1;
}
