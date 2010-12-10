/*
 * Copyright 2010, NagaChaitanya Vellanki
 *
 * Author NagaChaitanya Vellanki
 *
 * Euclid's algorithm
 * GCD(0,0) = 0,
 * GCD(a,b) = GCD(a-b,b) = GCD(a,b-a)
 * GCD(0,a) = GCD(a,0) = a for all a, b >= 0
 *
 * GCD(a,b) = GCD(a mod b, b) if a >= b
 * GCD(a,b) = GCD(a, b mod a) if b >= a
 *
 * Note: GMP is used here to allow arbitary precision inputs
 *       To compile using GMP use the following commandline
 *       (provided GMP is installed)
 *       g++ -lgmpxx euclid_algorithm.cpp
 *
 *      code can be modified easily to work without GMP
 */

#include <gmpxx.h>
#include <iostream>
#include <cstdlib>

using namespace std;

const mpz_class ZERO = 0;

mpz_class Euclid(mpz_class a, mpz_class b) {
  mpz_class m = a;
  mpz_class n = b;

  while((m != ZERO) && (n != ZERO)) {
    if(m >= n) {
      //m = m - n;
      m = m % n;
    } else {
      //n = n - m;
      n = n % m;
    }
  }

  if(m == ZERO) {
    return n;
  } else {
    return m;
  }
}

int main() {
  mpz_class a = ZERO;
  mpz_class b = ZERO;

  cout << "Enter a, b" << endl;
  cin >> a >> b;

  if((a < ZERO) || (b < ZERO)) {
    cout << "a,b should be greater than equal to zero" << endl;
    exit(0);
  }
  cout << "GCD of " << a << ", " << b << " is " <<  Euclid(a, b) << endl;
  return 0;
}
