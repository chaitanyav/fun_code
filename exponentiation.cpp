/*
 * Copyright 2010, NagaChaitanya Vellanki
 *
 * Author NagaChaitanya Vellanki
 *
 * Computing a^n in O(logn)
 */

#include <inttypes.h>
#include <iostream>
using namespace std;


int main() {
  int64_t base = 0;
  int64_t exponent = 0;
  int64_t result = 1;

  cout << "Enter base" << endl;
  cin >> base;

  cout << "Enter exponent" << endl;
  cin >> exponent;

  while(exponent != 0) {
    if((exponent % 2) == 0) {
      exponent = (exponent / 2);
      base = base * base;
    } else {
      exponent = exponent - 1;
      result = result * base;
    }
  }

  cout << "Result of a^n is " << result << endl;
  return 0;
}
