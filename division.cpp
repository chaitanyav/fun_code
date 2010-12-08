/*
 * Copyright 2010, NagaChaitanya Vellanki
 *
 * Author NagaChaitanya Vellanki
 *
 * Division with using division(/) or modulus operator(%)
 * a >= 0 b > 0 , a = (quotient * b) + remainder, 0 <= remainder < b
 */

#include <inttypes.h>
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int32_t a = 0;
  int32_t b = 0;
  int32_t remainder = 0;
  int32_t quotient = 0;

  cout << "Enter a" << endl;
  cin >> a;

  if(a < 0) {
    cout << "a should be greater than equal to zero" << endl;
    exit(0);
  }

  cout << "Enter b" << endl;
  cin >> b;

  if(b <= 0) {
    cout << "b should be greater than zero" << endl;
    exit(0);
  }

  remainder = a;
  while(remainder >= b) {
    remainder = remainder - b;
    quotient += 1;
  }

  cout << "Quotient is " << quotient << " Remainder is " << remainder << endl;
  return 0;
}
