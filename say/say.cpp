#include "say.h"
#include <cmath>
#include <map>

using namespace std;

string say::in_english(uint64_t number) {
  map<uint64_t, string> words = {{0, "zero"},          {1, "one"},
                                 {2, "two"},           {3, "three"},
                                 {4, "four"},          {5, "five"},
                                 {6, "six"},           {7, "seven"},
                                 {8, "eight"},         {9, "nine"},
                                 {10, "ten"},          {11, "eleven"},
                                 {12, "twelve"},       {13, "thirteen"},
                                 {14, "fourteen"},     {15, "fifteen"},
                                 {16, "sixteen"},      {17, "seventeen"},
                                 {18, "eighteen"},     {19, "nineteen"},
                                 {20, "twenty"},       {30, "thirty"},
                                 {40, "forty"},        {50, "fifty"},
                                 {60, "sixty"},        {70, "seventy"},
                                 {80, "eighty"},       {90, "ninety"},
                                 {100, "hundred"},     {1000, "thousand"},
                                 {1000000, "million"}, {1000000000, "billion"}};
  string spelling = "";
  if (number == 0) {
    return "zero";
  }
  if (number >= 1000000000) {
    spelling = spelling + words[number / 1000000000] + " billion";
    number = number % 1000000000;
    if (number > 0) {
      spelling = spelling + " ";
    }
  }
  if (number >= 1000000) {
    spelling = spelling + words[number / 1000000] + " million";
    number = number % 1000000;
    if (number > 0) {
      spelling = spelling + " ";
    }
  }
  if (number >= 1000) {
    spelling = spelling + words[number / 1000] + " thousand";
    number = number % 1000;
    if (number > 0) {
      spelling = spelling + " ";
    }
  }
  if (number >= 100) {
    spelling = spelling + words[number / 100] + " hundred";
    number = number % 100;
    if (number > 0) {
      spelling = spelling + " ";
    }
  }
  if (number > 20) {
    spelling = spelling + words[(number / 10) * 10] + "-";
    number = number % 10;
  }
  if (number > 0) {
    spelling = spelling + words[number];
  }
  return spelling;
}
