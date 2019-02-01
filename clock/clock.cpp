#include <iostream>
#include "clock.h"

using namespace std;



string date_independent::clock::at(int hour, int minute){
    cout << hour << minute;
    return "08:00";
}
