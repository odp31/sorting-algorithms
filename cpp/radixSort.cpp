#include <iostream>
#include <vector>

using namespace std;

void radixSort(vector<int>& arr) {
  int max = *max_element(arr.begin(), arr.end());

  // find max num of digits
  int exp = 1;
  while(max / exp > 0) {
    // create bucket for each digit (0 - 9)
    vector<vector<int>> buckets(10);

    // distribute elements into buckets based on current digit
    for(int num: arr) {
      int digit = (num / exp) % 10;
      buckets[digit].push_back(num);
    }
    // gather elements from buckets back into array
    int index = 0;
    for(auto& bucket : buckets) {
      for(int num : bucket) {
        arr[index++] = num;
      }
    }
    exp *= 10;
  }
}

int main() {
  vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
  radixSort(arr);
  for(int num : arr) {
    cout << num << " ";
  }
  cout << end1;
  return 0;
}
