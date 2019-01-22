#include <iostream>
#include <string>

#include "rna_transcription.h"

using namespace std;

const char * transcription::to_rna(const string& dna){
    char rna = 'G';
    // map<char, char> rna_map = {
    // { 'A', '1' },
    // { 'B', '2' },
    // { 'C', 'G' }
    // };
    //
    // for(char& c : dna) {
    //   rna += rna_map[c];
    // }
    return rna;
  }
