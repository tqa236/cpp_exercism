#include "food_chain.h"

using namespace std;


string food_chain::verse(int verse){
    if (verse == 1){
        return "I know an old lady who swallowed a fly.\n"
            "I don't know why she swallowed the fly. Perhaps she'll die.\n";
    }
    if (verse == 2){
        return "I know an old lady who swallowed a spider.\n"
            "It wriggled and jiggled and tickled inside her.\n"
            "She swallowed the spider to catch the fly.\n"
            "I don't know why she swallowed the fly. Perhaps she'll die.\n";
    }
    return "";
}
