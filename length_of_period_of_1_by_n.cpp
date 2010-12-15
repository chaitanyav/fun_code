/*
 * Copyright 2010, NagaChaitanya Vellanki
 *
 * Author NagaChaitanya Vellanki
 *
 * Print length of the period of decimal representation of 1/n for n > 1
 */

#include <inttypes.h>
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int32_t n = 0;

  cout << "Enter n(n > 1)" << endl;
  cin >> n;

  if(n <= 1) {
    exit(0);
  }

  int32_t rem = 1;
  int32_t i = 0;

  // period of a fraction cannot be less than the period of sequence of
  // remainders
  while(i < n) {
    rem = (10 * rem) % n;
    i++;
  }

  // c is the (n + 1)th term in the sequence remainders
  int32_t c = rem;

  rem = (10 * rem) % n; // (n + 2)th term in the sequence of remainders
  i =  1;

  while(rem != c) {
    rem = (rem * 10) % n;
    i++;
  }

  cout << "The period length of " << 1 << "/" << n << " is " << i << endl;
  return 0;
}
