#include <stdio.h>

void radixSort(int arr[], int n) {
  // find max number to knwo number of digits
  int max = arr[0];
  for(int i = 1; i < n; i++)
    if(arr[i] > max)
      max  = arr[i];

  // do counting sort for every digit; instead of passing digit number, exp is passed 
  // exp is 10 ^ i where i is current digit number
  for(int exp = 1; max / exp > 0; exp *= 10) {
    int output[n];
    int count[10] = {0};

    // store count of occurrences in count[]
    for(int i = 0; i < n; i++)
      count[(arr[i] / exp) % 10]++;

    // change count[i] so it contains actual position of this digit in output
    for(int i = 1; i < 10; i++)
      count[i] += count[i - 1];

    // build output array
    for(int i = n - 1; i >= 0; i--) {
      output[count[(arr[i] / exp) % 10] - 1] = arr[i];
      count[(arr[i] / exp) % 10]--;
    }
    // copy output array to arr[]
    for(int i = 0; i < n; i++)
      arr[i] = output[i];
  }
}

// function to print array
void printArray(int arr[], int n) {
  for(int i = 0; i < n; i++)
    printf("%d ", arr[i]);
}

int main() {
  int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
  int n = sizeof(arr) / sizeof(arr[0]);

  radixSort(arr, n);
  printArray(arr, n);
  return 0;
}
