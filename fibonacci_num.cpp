/*
 * Copyright 2010, NagaChaitanya Vellanki
 *
 * Author NagaChaitanya Vellanki
 *
 * Fibonacci Numbers
 * F(n) = F(n - 1) + F(n - 2) for n >= 2
 * F(0) = 0, F(1) = 1
 */

#include <inttypes.h>
#include <iostream>
#include <cmath>

using namespace std;

// using recursion

int64_t fibonacci_r(int32_t n) {
  if(n == 0) {
    return 0;
  }

  if(n == 1) {
    return 1;
  }

  return(fibonacci_r(n - 1) + fibonacci_r(n - 2));
}

// using the identity
// F(n) = (Phi^n - (1 - Phi)^n) / sqrt(5)
// where Phi = (1 + sqrt(5)) / 2

int64_t fibonacci(int32_t n) {
  double sqrt_5 = sqrt(5);
  double phi = (1 + sqrt_5) / 2;

  return ceil((pow(phi, n) - pow((1 - phi), n)) / sqrt_5);
}

int main(int argc, char* argv[]) {

  cout << fibonacci_r(0) << endl;
  cout << fibonacci_r(1) << endl;
  cout << fibonacci_r(2) << endl;
  cout << fibonacci_r(3) << endl;
  cout << fibonacci_r(4) << endl;
  cout << fibonacci_r(5) << endl;

  cout << "--------------" << endl;
  cout << fibonacci(0) << endl;
  cout << fibonacci(1) << endl;
  cout << fibonacci(2) << endl;
  cout << fibonacci(3) << endl;
  cout << fibonacci(4) << endl;
  cout << fibonacci(5) << endl;

  return 0;
}
