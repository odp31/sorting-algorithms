#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(int arr[], int n) {
  // find max and min values
  int maxVal = arr[0], minVal = arr[0];
  for(int i = 1; i < n; i++) {
    maxVal = max(maxVal, arr[i]);
    minVal = min(minVal, arr[i]);
  }
  // calculate range and number of buckets
  int range = maxVal - minVal + 1;
  int numBuckets = sqrt(n);

  // create buckets
  vector<vector<int>> buckets(numBuckets);

  // distribute elements into buckets
  for(int i = 0; i < n; i++) {
    int bucketIndex = (int)(((arr[i] - minVal) * (numBuckets - 1)) / range);
    buckets[bucketIndex].push_back(arr[i]);
  }
  // sort each bucket
  for(auto& bucket: buckets) {
    sort(bucket.begin(), bucket.end());
  }
  // concatenate sorted buckets
  int index = 0;
  for(auto& bucket : buckets) {
    for(int num : bucket) {
      arr[index++] = num;
    }
  }
}
int main() {
  int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
  int n = sizeof(arr) / sizeof(arr[0]);

  bucketSort(arr, n);
  cout << "sorted array: \n";
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << end1;
  return 0;
}
