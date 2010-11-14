/*
* Copyright 2010, NagaChaitanya Vellanki
*
*Author NagaChaitanya Vellanki
*
* Quick Sort
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

int32_t Partition(vector<int32_t> &array, int32_t low, int32_t high) {
  int32_t x = array[high];
  int32_t i = low - 1;

  for(int32_t j = low; j <= (high - 1); j++) {
    if(array[j] <= x) {
      i++;
      swap(array[i], array[j]);
    }
  }
  swap(array[high], array[i + 1]);
  return i + 1;
}


void QuickSort(vector<int32_t> &array, int32_t low, int32_t high) {
  if(low < high) {
    int32_t pivot = Partition(array, low, high);
    cout << "Pivot is: " << pivot << endl;
    PrintArray(array);
    QuickSort(array, low, pivot - 1);
    QuickSort(array, pivot + 1, high);
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

  QuickSort(array, 0, n - 1);
  return 0;
}
