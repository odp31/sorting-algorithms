#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
  // find max and min values
  int maxVal = arr[0], minVal = arr[0];
  for(int i = 1; i < n; i++) {
    maxVal = max(maxVal, arr[i]);
    minVal = min(minVal, arr[i]);
  }
  // calculate range and num buckets
  int range = maxVal - minVal + 1;
  int numBuckets = (int)sqrt(n);

  // create buckets
  int** buckets = (int**)malloc(numBuckets * sizeof(int*));
  for(int i = 0; i < numBuckets; i++) {
    buckets[i] = (int*)malloc(n/ numBuckets * sizeof(int));
    int j;
    for(j = 0; j < n / numBuckets; j++) {
      buckets[i][j] = -1;
    }
  }
  // distribute elemetns into buckets
  for(int i = 0; i < n; i++) {
    int bucketIndex = (int)(((arr[i] - minVal) * (numBuckets - 1)) / range);
    int j;
    for(j = 0; j < n / numBuckets; j++) {
      if(buckets[bucketIndex][j] == -1) {
        buckets[bucketIndex][j] = arr[i];
        break;
      }
    }
  }
// sort each bucket 
for(int i = 0; i < numBuckets; i++) {
  for(int j = 1; j < n / numBuckets; j++) {
    int key = buckets[i][j];
    int k = j - 1;
    while(k >= 0 && buckets[i][k] > key) {
      buckets[i][k+1] = buckets[i][k];
      k = k - 1;
    }
    buckets[i][k+1] = key;
  }
}
// concatenate sorted buckets
int index = 0;
for(int i = 0; i < numBuckets; i++) {
  for(int j = 0; j < n / numBuckets; j++) {
    if(buckets[i][j] != -1) {
      arr[index++] = buckets[i][j];
    }
  }
}
// free memory
for(int i = 0; i < numBuckets; i++) {
  free(buckets[i]);
}
free(buckets);
}

int main() {
  int arr[] = {170, 45, 75, 90, 802, 24 ,2 ,66};
  int n = sizeof(arr) / sizeof(arr[0]);

  bucketSort(arr, n);
  printf("sorted array: \n");
  for(int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
