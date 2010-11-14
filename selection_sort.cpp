/*
 *Copyright 2010, NagaChaitanya Vellanki
 *
 *Author NagaChaitanya Vellanki
 *
 * Selection sort , complexity O(n^2)
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

void SelectionSort(vector<int32_t> &array) {
  int32_t num_elements = array.size();

  for (int32_t i = 0; i < num_elements; i++) {
    int32_t min = i;
    for (int32_t j = i + 1; j < num_elements; j++) {
      if(array[j] < array[min]) {
        min = j;
      }
    }
    int32_t temp = array[i];
    array[i] = array[min];
    array[min] = temp;
    cout << "Iteration: " << endl;
    PrintArray(array);
  }
}

int main() {
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

  SelectionSort(array);
  return 0;
}
