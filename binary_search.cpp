/*
 *Copyright 2010, NagaChaitanya Vellanki
 *
 *Author NagaChaitanya Vellanki
 *
 * Binary search using recusion and iteration
 */

#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>

using namespace std;

int32_t IterativeBinarySearch(vector<int32_t> &array, int32_t search_key)
{
  int32_t low = 0, mid = 0, high = 0;
  high = array.size();

  while (low < high)
    {
      mid = (low + high) / 2;
      if (search_key == array[mid])
        {
          return mid;
        }
      else if (search_key > array[mid])
        {
          low = mid + 1;
        }
      else
        {
          high = mid - 1;
        }
    }
  return -1;
}


int32_t RecursiveBinarySearch(vector<int32_t> &array, int32_t search_key, int32_t low, int32_t high) {

 if (low > high) {
   return -1;
 }

 int32_t mid = (low + high) / 2;
  if (search_key == array[mid]) {
    return mid;
  } else if ( search_key > array[mid]) {
    RecursiveBinarySearch(array, search_key, mid + 1, high);
  } else {
    RecursiveBinarySearch(array, search_key, low, mid - 1);
  }
}


int main()
{
  int32_t n = 0, search_key = 0;
  vector<int32_t> array;

  cout << "Enter the number of elements" << endl;
  cin >> n;

// read the elements
  cout << " ** Enter the elements of the array in sorted order **" << endl;
  for (int32_t index = 0; index < n; index++)
    {
      int32_t temp = 0;
      cin >> temp;
      array.push_back(temp);
    }

  cout << "Enter the element to search for" << endl;
  cin >> search_key;

  cout << IterativeBinarySearch(array, search_key) << endl;

  cout << RecursiveBinarySearch(array, search_key, 0, array.size());
  return 0;
}
