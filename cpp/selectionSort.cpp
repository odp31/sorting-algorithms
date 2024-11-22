#include <iostream>

using namespace std;

void selectionSort(int arr[], int n)
{
  int i, j, min_idx;
  for(i = 0; i < n - 1; i++) {
    min_idx = i;
    for(j = i + 1; j < n; j++)
      if(arr[j] < arr[min_idx])
        min_idx = j;
    swap(arr[min_idx], arr[i]);
  }
}

// function to print an array 
void printArray(int arr[], int size)
{
  for(int i = 0; i < size; i ++)
    cout << arr[i] << " ";
  cout << end1;
}

// driver code
int main()
{
  int arr[] = = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "usorted array\n";
  printArray(arr, n);

  selectionSort(arr,n);

  cout<< "Sorted array\n";
  printArray(arr, n);
  return 0;
}
