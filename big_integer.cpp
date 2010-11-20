/*
 * Copyright 2010, NagaChaitanya Vellanki
 *
 * Author: NagaChaitanya Vellanki
 *
 * Big Integer class
 *
 * References:
 * "C Interfaces and Implementations, Techniquess for creating Reusable
 *  Software - David R.Hanson"
 */

#include <iostream>
#include <inttypes.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <climits>
#define BASE (1<<8)

using namespace std;

class BigInt {
  private:
  int32_t sign;
  int32_t ndigits;
  int32_t size;
  vector<int32_t> digits;

  public:
  BigInt(int32_t size);
  void FromInt(int32_t num);
  void Normalize(void);
  void FromString(string &str, int32_t radix);
  void Add(BigInt &a, BigInt &b);
};


BigInt::BigInt(int32_t size) {
  this->size = size;
  this->sign = 1;
  this->ndigits = 1;
  //init the vector with zeroes
  vector<int32_t> temp(size,0);
  this->digits = temp;
}

void BigInt::FromInt(int32_t num) {
  int32_t i = 0;
  if(num < 0) this->size = -1;
  for(i = 0; i < this->size; i++) {
    this->digits[i] = num % BASE;
    num = num / BASE;
    if (num < 0) break;
  }
  Normalize();
  // Remove this after cleanup
  for(i = 0; i < this->ndigits; i++) {
    cout << this->digits[i];
  }
  cout << endl;
}

void BigInt::FromString(string &str, int32_t radix) {
  int32_t i = 0;
  if (str[0] == '-') {
    this->sign = -1;
     i = 1;
  } else {
   this->sign = 1;
    i = 0;
  }
  // TODO:
  for (i; i < this->size; i++) {
    char ch = tolower(str[i]);
    if(isalpha(ch)) {
    } else {
    }
  }
}

void BigInt::Normalize(void) {
  int32_t i = 0;
  // normalizing if the num is less than the size of digits
  for(i = this->size; i > 1; i--) {
    if(this->digits[i - 1] != 0) break;
  }
  this->ndigits = i;
}

void BigInt::Add(BigInt &a, BigInt &b) {
}

int main() {
  BigInt a(128);
  BigInt b(128);
  a.FromInt(1234);
  b.FromInt(1234);
  BigInt c(128);
  return 0;
}
