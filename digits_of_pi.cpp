/*
 * Copyright 2010, NagaChaitanya Vellanki
 *
 *Author NagaChaitanya Vellanki
 * Digits of Pi, This is a O(n^2) algorithm
 * References:
 * Stan Wagon. "A spigot algorithm for the digits of Pi" American Mathematical Monthly 102 (1995): 195-203.
 */

#include <iostream>
#include <stdint.h>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void PiSpigot(int32_t num_digits) {
  int32_t predigit = 0;
  int32_t carry = 0;
  int32_t num = 0;
  int32_t den = 0;
  int32_t quo = 0;
  int32_t rem = 0;
  int32_t nines = 0;
  // array of length floor(10n/3)
  int32_t n = ((10 * num_digits) / 3);
  int32_t array[n];
  //init array
  for(int32_t i = 0; i < n; i++) {
    array[i] = 2;
  }

  for(int32_t i = 0; i < num_digits; i++) {
    carry = 0;
    num = 0;
    den = 0;
    quo = 0;
    rem = 0;
    int32_t j = 0;
    // put A into regular form
    for(j = n; j > 1; j--) {
      num = j - 1;
      den = (2*j) - 1;
      array[j - 1] = array[j- 1] * 10 +  quo * (num + 1);
      quo = array[j - 1] / den;
      rem = array[j - 1] % den;
      array[j - 1] = rem;
    }

    // get the next predigit
    array[j - 1] = array[j - 1] * 10 + (quo);
    quo = array[j - 1]/10;
    array[j - 1] = array[j - 1]%10;

    // Adjust the predigits
    if(quo == 9) {
      nines++;
    } else {
      if(quo == 10) {
        cout << predigit + 1;
        for(int32_t k = 0; k < nines; k++) {
          cout << 0;
        }
        predigit = 0;
        nines = 0;
      } else {
        if(i!= 0)
          cout << predigit;
        predigit = quo;
        if(nines != 0) {
          for(int32_t k = 0; k < nines; k++) {
            cout << 9;
          }
          nines = 0;
        }
      }
    }
    if(i == 1) cout << ".";
  }
  cout << predigit;
}

int main()
{
  int32_t n = 0;
  cout << "Enter the number of digits" << endl;
  cin >> n;

  // pi-spigot
  PiSpigot(n);
  return 0;
}
