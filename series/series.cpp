#include "series.h"
#include <iostream>

using namespace std;

vector<int> series::digits(string number){
    vector<int> digits;
    for (unsigned int i = 0; i < number.size(); ++i)
    {
        digits.push_back(number[i] - '0');
    }
    return digits;
}

vector<vector<int>> series::slice(string number, int length){
    if (number.size() < (unsigned int)length){
        throw domain_error("This number is not long enough.");
    }
    vector<int> digits = series::digits(number);
    vector<vector<int>> subset;
    for (unsigned int i = 0; i < number.size() - length + 1; i = i + 1)
    {
        subset.push_back(vector<int>(digits.begin() + i,
         digits.begin() + i + length));
    }
    return subset;
}
