#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  // if left child > root
  if(l < n && arr[l] > arr[largest])
    largest = l;

  // if right child > largest so far
  if(r < n && arr[r] > arr[largest])
    largest = r;

  // if largest is not root
  if(largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

// main function to do heapsort
void heapSort(int arr[], int n) {
  // build heap (rearrange array)
  for(int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // one by one extract element from heap
  for(int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}
// function to print array
void printArray(int arr[], int n) {
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << "\n";
}

// driver program
int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  heapSort(arr, n);
  cout << "sorted array is \n";
  printArray(arr, n);
  return 0;
}
