/*
 *
 * Copyright 2011, NagaChaitanya Vellanki
 *
 *
 * Author NagaChaitanya Vellanki
 *
 * Sieve of Atkin http://en.wikipedia.org/wiki/Sieve_of_Atkin
 *
 */

#include <stdint.h>
#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

int main() {
  const int64_t N = 100000000;
  bitset<N> sieve;

  sieve.reset();
  sieve.flip(0);
  sieve.flip(1);
  sieve.flip(2);
  sieve.flip(3);

  int64_t sqrt_n = (int64_t) sqrt(N) + 1;

  for(int64_t x = 1; x < sqrt_n; x++) {
    for(int64_t y = 1; y < sqrt_n; y++) {
      int64_t n = 4 * (x * x) + (y * y);

      if((n <= N) && ((n % 12 == 1) || (n % 12 ==5))) {
        sieve.flip(n - 1);
      }

      n = 3 * (x * x) + (y * y);
      if((n <= N) && (n % 12 == 7)) {
        sieve.flip(n - 1);
      }

      n = 3 * (x * x) - (y * y);
      if((x > y) && (n <= N) && (n % 12 == 11)) {
        sieve.flip(n - 1);
      }

    }
  }

  for(int64_t n = 5; n < sqrt_n; n++) {
    if(sieve[n - 1] == 1) {
      int64_t sqr_n = (n * n);
      for(int64_t i = sqr_n; i <= N; i += sqr_n) {
        sieve[i - 1] = 0;
      }
    }
  }

  //for(int64_t n = 5; n <= N; n++) {
    //if(sieve[n - 1] == 1) {
      //cout << n << endl;
    //}
  //}
  return 0;
}
