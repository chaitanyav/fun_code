/*
 * Copyright 2010, NagaChaitanya Vellanki
 *
 * Author NagaChaitanya Vellanki
 *
 * Swapping two variables without auxillary
 */

#include <iostream>
#include <inttypes.h>

using namespace std;

int main()
{
  int32_t a = 10;
  int32_t b = 20;
  cout << "a is " << a << ",b is " << b << endl;
  a = a + b;
  b = a - b;
  a = a - b;
  cout << "After Swapping " << endl;
  cout << "a is " << a << ",b is " << b << endl;
  return 0;
}
