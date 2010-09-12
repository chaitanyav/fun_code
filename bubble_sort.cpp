/*
 *Copyright 2010, NagaChaitanya
 *
 *Author NagaChaitanya Vellanki
 *
 *Bubble sort, complexity O(n^2)
 */

#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>

using namespace std;


void BubbleSort(vector<int32_t> &array)
{
  int32_t num_elements = array.size();
  for (int32_t i = 0; i < num_elements; i++)
    {
      for (int32_t j = 0; j < (num_elements - i - 1); j++)
        {
          if (array[j] > array[j + 1])
            {
              int32_t temp = array[j];
              array[j] = array[j + 1];
              array[j + 1] = temp;
            }
        }
    }
}

void PrintArray(vector<int32_t> &array)
{
  for (int32_t index = 0; index < array.size(); index++)
    {
      cout << array[index] << endl;
    }
}


int main()
{
  int32_t n = 0;
  vector<int32_t> array;

  cout << "Enter the number of elements" << endl;
  cin >> n;

  // read the elements
  cout << " ** Enter the elements of the array **" << endl;
  for (int32_t index = 0; index < n; index++)
    {
      int32_t temp = 0;
      cin >> temp;
      array.push_back(temp);
    }

  BubbleSort(array);
  PrintArray(array);

  return 0;
}
