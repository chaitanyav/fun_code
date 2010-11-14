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

void printArray(vector<int32_t> &array)
{
  for (int32_t i = 0; i < array.size(); i++)
    {
      cout << array[i] << " ";
    }
  cout << endl;
}

void insertionSort(vector<int32_t> &array)
{
  for (int32_t j = 1; j < array.size(); j++)
    {
      int32_t key = array[j];
      int32_t i = j - 1;
      // move elements to the right
      while ( (i >= 0) & (array[i] > key))
        {
          array[i + 1] = array[i];
          i--;
        }
      // insert the element into its right place
      array[i + 1] = key;
      cout << "Iteration: " << endl;
      printArray(array);
    }
}

int main()
{
  int32_t n = 0;
  int32_t num = 0;
  vector<int32_t> array;

  cout << "Enter the number of elements" << endl;
  cin >> n;

  cout << "Enter the elements" << endl;

  for (int32_t i = 0; i < n; i++)
    {
      cin >> num;
      array.push_back(num);
    }

  insertionSort(array);
  return 0;
}


