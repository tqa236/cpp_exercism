#include <iostream>
#include <sstream>
#include "clock.h"

using namespace std;



date_independent::clock::at(int hour, int minute){
    stringstream ret;
    while (minute < 0){
        minute = minute + 60;
        hour = hour - 1;
    }
    while (hour < 0){
        hour = hour + 24;
    }
    hour = (hour + minute/60) % 24;
    minute = minute % 60;
    if (hour < 10){
        ret << "0";
    }
    ret << hour <<":";
    if (minute < 10){
        ret << "0";
    }
    ret << minute;
    return ret.str();
}

date_independent::clock::operator std::string() const {
  int hours = (min_ / 60) % 24;
  int minutes = min_ % 60;
  char res [5];
  snprintf(res, "%02d:%02d", hours, minutes);
  return res;
}
