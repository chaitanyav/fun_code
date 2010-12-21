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
  const int64_t N = 1000000000;
  bitset<N> sieve;

  sieve.set(); // set all bits
  sieve.reset(0); // clearing the first bit

  int64_t sqrt_n = (int64_t)sqrt(N) + 1;
  for(int64_t num = 2; num < sqrt_n; num++) {
    if(sieve[num - 1] == 1) {
      for(int64_t mnum = num * num; mnum <= N; mnum += num) {
        sieve.reset(mnum - 1);
      }
    }
  }

  // using the sieve to print primes
  //for(int64_t i = 2; i <= N; i++) {
    //if(sieve[i - 1] == 1) {
      //cout << i << endl;
    //}
  //}

  return 0;
}
