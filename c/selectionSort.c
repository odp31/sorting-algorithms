// time complexity- O(n^2)
// space complexity - O(1)

#include <stdio.h>
void selectionSort(int arr[], int n)
{
  int i, j, min_idx;
  // one by one move boundary of unsorted subarray
  for (i = 0; i < n - 1; i++) {
    // find min element of unsorted array 
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;
// swap element found min element with first element 
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}
