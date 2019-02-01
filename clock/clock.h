#pragma once
#include <string>

namespace date_independent {
    using namespace std;
    class clock{
    private:
        int hour, minute;
    public:
        clock(int hour_, int minute_){
            hour = hour_;
            minute = minute_;
        };
        string at(int, int);
    };
}
