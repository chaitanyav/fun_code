/*
 * Copyright 2010, NagaChaitanya Vellanki
 *
 * Author NagaChaitanya Vellanki
 *
 * Print the decimal representation of a positive integer in reverse
 */

#include <inttypes.h>
#include <iostream>

using namespace std;

int main() {
  int32_t n = 123456;

  while(n > 0) {
    cout << (n%10);
    n /= 10;
  }
  return 0;
}
