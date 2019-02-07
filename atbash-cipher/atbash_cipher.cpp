#include "atbash_cipher.h"
#include <algorithm>

using namespace std;

string atbash::encode(string text){
    string cipher;
    int count = 0;
    std::replace_if(text.begin(), text.end(), ::ispunct, ' ');
    text.erase(remove(text.begin(), text.end(), ' '), text.end());
    for(const char& c : text) {
        if ((count % 5 == 0) && (count > 0)){
            cipher = cipher + ' ';
        }
        if (isdigit(c)){
            cipher = cipher + c;
        }
        else{
            cipher = cipher + (char)('a' + 'z' - tolower(c));
        }
        count = count + 1;

    }
    return cipher;
}

string atbash::decode(string text){
    string cipher = atbash::encode(text);
    cipher.erase(remove(cipher.begin(), cipher.end(), ' '), cipher.end());
    return cipher;
}
