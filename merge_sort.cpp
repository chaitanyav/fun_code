/*
* Copyright 2010, NagaChaitanya Vellanki
*
*Author NagaChaitanya Vellanki
*
* Merge Sort, complexity O(n *lg(n))
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

void Merge(vector<int32_t> &array, int32_t low, int32_t mid,  int32_t high)
{
  int32_t n1 = mid - low + 1;
  int32_t n2 = high -mid;
  int32_t left[n1 + 1];
  int32_t right[n2 + 1];

  for(int32_t i = 0; i < n1; i++) {
    left[i] = array[low + i - 1];
  }

  for(int32_t i = 0; i < n2; i++) {
    right[i] = array[i + mid];
  }

  // sentinels
  left[n1] = 9999;
  right[n2] = 9999;

  int32_t i = 0;
  int32_t j = 0;

  for(int32_t k = low - 1; k < high; k++) {
    if(left[i] <= right[j]) {
      array[k] = left[i];
      i++;
    } else {
      array[k] = right[j];
      j++;
    }
  }
  cout << "Step:" << endl;
  PrintArray(array);
}

void MergeSort(vector<int32_t> &array, int32_t low, int32_t high)
{
  if (low < high)
    {
      int32_t mid = (low + high) / 2;
      MergeSort(array, low, mid);
      MergeSort(array, mid + 1, high);
      Merge(array, low, mid, high);
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

  MergeSort(array, 1, n);
  return 0;
}
