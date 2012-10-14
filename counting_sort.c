#include <stdio.h>

int main() {
  int output[16], count[6], i = 0;
  int input[16] = {1, 4, 4, 5, 0, 5, 3, 1, 1, 2, 4, 1, 1, 5, 5, 5};

  for(i = 0; i < 6; i++){
    count[i] = 0;
  }

  printf("Input: ");
  for(i = 0; i < 16; i++) {
    count[input[i]] = count[input[i]] + 1;
    printf(" %d ", input[i]);
    output[i] = 0;
  }
  printf("\n");


  for(i = 1; i < 6; i++) {
    count[i] += count[i - 1];
  }

  printf("\n");
  for(i = 16; i > 0; i--) {
    output[count[input[i-1]] - 1] = input[i-1];
    count[input[i-1]] -= 1;
  }


  printf("Output: ");
  for(i = 0; i < 16; i++) {
    printf(" %d ", output[i]);
  }

  printf("\n");
  return 0;
}
