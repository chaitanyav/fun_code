/*
 *Copyright 2010, NagaChaitanya Vellanki
 *
 *Author NagaChaitanya Vellanki
 *
 * Sieve of Eratosthenes
 */

#include <stdint.h>
#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;


int main() {
  const int64_t n = 100000000;
  bitset<n> sieve;

  sieve.set(); // set all bits
  sieve.reset(0); // clearing the first bit

  int64_t sqrt_n = (int64_t)sqrt(n) + 1;
  for(int64_t num = 2; num < sqrt_n; num++) {
    if(sieve[num - 1] == 1) {
      for(int64_t mnum = num * num; mnum <= n; mnum += num) {
        sieve.reset(mnum - 1);
      }
    }
  }

  // using the sieve to print primes
  //for(int64_t i = 2; i <= n; i++) {
    //if(sieve[i - 1] == 1) {
      //cout << i << endl;
    //}
  //}

  return 0;
}
