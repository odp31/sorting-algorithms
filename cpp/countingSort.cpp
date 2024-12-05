#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int>& arr) {
  int max = *max_element(arr.begin(), arr.end());

  // create count array to store count of each element
  vector<int> count(max + 1, 0);

  // store count of each element in count array
  for(int num: arr) {
    count[num]++;
  }
  // modify count array to store position of element 
  for(int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }
  // build sorted array
  vector<int> output(arr.size());
  for(int i = arr.size() - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  // copy sorted elements to original array 
  arr = output;
}

int main() {
  vector<int> arr = {64, 25, 12, 22, 11};
  countingSort(arr);

  cout << "sorted array: ";
  for(int num : arr) {
    cout << num << " ";
  }
  cout << end1;
  return 0;
}
