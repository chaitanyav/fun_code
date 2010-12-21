/*
 *Copyright 2010, NagaChaitanya Vellanki
 *
 *Author NagaChaitanya Vellanki
 *
 * Pritchard's linear sieve
 */

#include <stdint.h>
#include <iostream>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <vector>

using namespace std;

void SieveEratosthenes(vector<int64_t> &primes, int64_t n) {
  vector<bool> sieve(n, true);
  sieve[0] = false;

  int64_t sqrt_n = (int64_t)sqrt(n) + 1;

  for(int64_t num = 2; num < sqrt_n; num++) {
    if(sieve[num - 1] == true) {
      for(int64_t mnum = num * num; mnum <= n; mnum += num) {
        sieve[mnum - 1] = false;
      }
    }
  }

  // using the sieve to get list of  primes
  for(int64_t i = 2; i <= n; i++) {
    if(sieve[i - 1] == true) {
      primes.push_back(i);
    }
  }


}

int main() {
  const int64_t N = 1000000000;

  bitset<N> sieve;
  sieve.set(); // set all bits
  sieve.reset(0); // clearing the first bit


  int64_t sqrt_n = (int64_t)sqrt(N) + 1;

  vector<int64_t> primes;
  SieveEratosthenes(primes, sqrt_n);


  for(int64_t i = 2; i <= (N / 2); i++) {
    for(int64_t j = 0; j< primes.size(); j++) {
      if(primes[j] > (N / i)) {
        break;
      }

      sieve.reset((primes[j] * i) - 1);

      if((i % primes[j]) == 0) {
        break;
      }
    }
  }

  // using the sieve to get list of  primes
  //for(int64_t i = 2; i <= N; i++) {
  //  if(sieve[i - 1] == 1) {
  //    cout << i << endl;
  //  }
  //}

  return 0;
}
