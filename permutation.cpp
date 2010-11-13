/*
 * Copyright 2010, NagaChaitanya Vellanki
 *
 * Author NagaChaitanya Vellanki
 *
 */

#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>

using namespace std;

void PrintArray(vector<int32_t> &array)
{
  for (int32_t index = 0; index < array.size(); index++)
  {
    cout << array[index] << " ";
  }
  cout << endl;
}

/*
 *Generate Lexiographic permutation of a given array of sorted elements
 * Refer to The Art of Computer Programming, Volume 4, Fascicle 2
 *
 */
void Permutation(vector<int32_t> &array, int32_t n) {
  while(true) {
    PrintArray(array);
    int32_t j = n - 1;

    // Find j
    while(array[j] >= array[j + 1]) {
      if(j == 0) return;
      j--;
    }

    // Increase aj
    int32_t l = n;

    while(array[j] >= array[l]) {
      if(l > 0) {
        l--;
      } else {
        break;
      }
    }


    // swap aj, al
    swap(array[j], array[l]);

    // Reverse aj+1 ... an
    int32_t k = j + 1;
    l = n;

    while(k < l) {
      swap(array[k],array[l]);
      k++;
      l--;
    }
  }
}

int main()
{
  int32_t n = 0;
  int32_t temp = 0;
  vector<int32_t> array;

  cout << "Enter the number of elements" << endl;
  cin >> n;

  // read the elements
  cout << " ** Enter the elements of the array **" << endl;
  for (int32_t index = 0; index < n; index++)
  {
    cin >> temp;
    array.push_back(temp);
  }

  cout << endl;
  Permutation(array, n - 1);
  return 0;
}
