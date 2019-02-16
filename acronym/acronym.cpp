#include <iostream>
#include <string>

using namespace std;

namespace acronym {
    string acronym(string name){
        string acronym_name = "";
        bool flag = true;
        for(char& c : name) {
            if (isalpha(c)){
                if (flag){
                    acronym_name += toupper(c);
                    flag = false;
                }
            }
            else{
                flag = true;
            }
        }
        return acronym_name;
    }
}
