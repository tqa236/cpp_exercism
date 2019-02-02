#include <stdexcept>
#include <algorithm>
#include "beer_song.h"

using namespace std;


string beer::verse(int verse_num){
    if (verse_num == 0){
        return "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n";
    }
    if (verse_num == 1){
        return to_string(verse_num) + " bottle of beer on the wall, " + to_string(verse_num) + " bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall.\n";
    }
    if (verse_num == 2){
        return to_string(verse_num) + " bottles of beer on the wall, " + to_string(verse_num) + " bottles of beer.\nTake one down and pass it around, " + to_string(verse_num - 1) + " bottle of beer on the wall.\n";
    }
    return to_string(verse_num) + " bottles of beer on the wall, " + to_string(verse_num) + " bottles of beer.\nTake one down and pass it around, " + to_string(verse_num - 1) + " bottles of beer on the wall.\n";
}

string beer::sing(int start, int end){
    string lyrics = "";
    for (int i = start; i > end - 1; i = i - 1){
        lyrics = lyrics + "\n" + beer::verse(i);
    }
    return lyrics.erase(0, 1);;
}

string beer::sing(int start){
    return beer::sing(start, 0);
}
