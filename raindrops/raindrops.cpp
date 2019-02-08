#include "raindrops.h"

using namespace std;

string raindrops::convert(int number){
    string raindrop = "";
    if (number % 3 == 0){
        raindrop = raindrop + "Pling";
    }
    if (number % 5 == 0){
        raindrop = raindrop + "Plang";
    }
    if (number % 7 == 0){
        raindrop = raindrop + "Plong";
    }
    if (raindrop == ""){
        return to_string(number);
    }
    return raindrop;
}
