#include "prime_factors.h"
#include <math.h>
#include <iostream>

using namespace std;

vector<int> prime_factors::primes(int number) {
  vector<int> primes;
  vector<int> numbers;
  for (int i = 1; i <= number; i++) {
    numbers.push_back(i);
  }
  for (int i = 2; i <= number; i++) {
    if (numbers[i - 1] != 0) {
      primes.push_back(numbers[i - 1]);
      for (int j = 2 * numbers[i - 1]; j <= number; j += numbers[i - 1]) {
        numbers[j - 1] = 0;
      }
    }
  }
  return primes;
}

vector<int> prime_factors::of(int number) {
  vector<int> factors;
  vector<int> primes = prime_factors::primes((int)sqrt(number) + 1);
  for (auto const& prime : primes) {
    while (number % prime == 0) {
      factors.push_back(prime);
      number = number / prime;
    }
  }
  if (number > 1) {
    factors.push_back(number);
  }
  return factors;
}
