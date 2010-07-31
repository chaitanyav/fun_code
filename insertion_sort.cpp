/*
   Copyright 2010, NagaChaitanya Vellanki

   Author NagaChaitanya Vellanki

   The following program performs insertion sort on an
   array of elements. The complexity is of the order of O(n^2)
   */

#include <iostream>
#include <stdint.h>
#include <algorithm>
#include <vector>

using namespace std;

void insertionSort(vector<uint32_t> &array)
{
  for (uint32_t j = 1; j < array.size(); j++)
    {
      uint32_t key = array[j];
      uint32_t i = j - 1;
      // move elements to the right
      while ( (i >= 0) & (array[i] > key))
        {
          array[i + 1] = array[i];
          i--;
        }
      // insert the element into its right place
      array[i + 1] = key;
    }
}


void printArray(vector<uint32_t> &array)
{
  for (uint32_t i = 0; i < array.size(); i++)
    {
      cout << array[i] << endl;
    }
}

int main()
{
  uint32_t n = 0;
  vector<uint32_t> array;

  cout << "Enter the number of elements" << endl;
  cin >> n;

  cout << "Enter the elements" << endl;

  for (uint32_t i = 0; i < n; i++)
    {
      uint32_t num = 0;
      cin >> num;
      array.push_back(num);
    }

  insertionSort(array);

  printArray(array);

  return 0;
}


