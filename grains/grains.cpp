#include "grains.h"
#include <cmath>

unsigned long long int grains::square(const int number){
    return (unsigned long long int)pow(2, (number - 1));
}

unsigned long long int grains::total(){
    return (unsigned long long int)pow(2, 64) - 1;
}
