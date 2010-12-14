/*
 * Copyright 2010, NagaChaitanya Vellanki
 *
 * Author NagaChaitanya Vellanki
 *
 * Print k digits of decimal representation of 1/n for n > 1
 */

#include <inttypes.h>
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int32_t n = 0;
  int32_t k = 1;

  cout << "Enter n(n > 1) and number of digits k (k >= 1)" << endl;
  cin >> n >> k;

  if((n <= 1) || (k < 1)) {
    exit(0);
  }

  int32_t i = 0;
  int32_t rem = 1;
  while(i < k) {
    cout << (10 * rem) / n;
    rem = (10 * rem) % n;
    i++;
  }

  return 0;
}
