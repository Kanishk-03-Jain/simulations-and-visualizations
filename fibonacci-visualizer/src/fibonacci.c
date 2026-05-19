#include "../include/fibonacci.h"

int numbers[COUNT + 2];

void generateFibonacciNumbers() {
  numbers[0] = 0;
  numbers[1] = 1;

  for (int i = 2; i <= COUNT + 1; i++) {
    numbers[i] = numbers[i - 1] + numbers[i - 2];
  }
}