/*
 * Copyright 2010, NagaChaitanya Vellanki
 *
 * Author NagaChaitanya Vellanki
 *
 * n! = n * (n - 1) * (n - 2) * .... 1
 */

#include <inttypes.h>
#include <iostream>

using namespace std;

uint64_t Factorial(uint64_t n) {
  if(n == 1) {
    return 1;
  } else {
    return n * Factorial(n - 1);
  }
}


int main() {
  for(uint64_t i = 1; i <= 64; i++) {
    cout << "Factorial of " << i << " is " << Factorial(i) << endl;
  }
  return 0;
}
