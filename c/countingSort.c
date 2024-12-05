#include <stdio.h>
#include <stdlib.h>

void countingSort(int array[], int size) {
  // find max element in array 
  int max = array[0];
  for(int i = 1; i < size; i++){
    if(array[i] > max) {
      max = array[i];
    }
  }

// create count array to store count of each element
int *count = (int*)calloc(max+1, sizeof(int));

// store count of each element in count array
for(int i = 0; i < size; i++) {
  count[array[i]]++;
}

// modify count array to store actual position of the element 
for(int i = 1; i <= max; i++) {
  count[i] += count[i - 1];
}

// build sorted array 
int *output = (int*)malloc(size * sizeof(int));
for(int i = size - 1; i >= 0; i--) {
  output[count[array[i]] - 1] = array[i];
  count[array[i]]--;
}

// copy sorted elements back to original array 
for(int i = 0; i < size; i++) {
  array[i] = output[i];
}
free(count);
free(output);
}

int main() {
  int array[] = {64, 25, 12, 22, 11};
  int size = sizeof(array) / sizeof(array[0]);
  countingSort(array, size);
  printf("sorted array; \n");
  for(int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}
