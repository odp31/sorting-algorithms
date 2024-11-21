#include <iostream>

using namespace std;

void merge(int array[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  intL[n1], R[n2];

  for(int i = 0; i < n1; i++)
    L[i] = array[left + i];
  for(int j = 0; j < n2; j++)
    R[j] = array[mid + 1 + j];

  int i = 0, j = 0, k = left;

  while(i < n1 && j < n2){
      if(L[i] <= R[j]) {
        array[k] = L[i];
        i++;
      } else {
              array[k] = R[j];
              j++;
      }
      k++;
  }

  while(i < n1) {
    array[k] = L[i];
    i++;
    k++;
  }
  while(j < n2) {
    array[k] = R[j];
    j++;  
    k++;
  |}
}

void mergeSort(int array[], int left, int right)
{
  if(left >= right)
    return;

  int mid = left + (right - left) / 2;

  mergeSort(array, left, mid);
  mergeSort(array, mid + 1, right); 

  merge(array, left, mid, right);
}

void printArray(int A[], int size)
{
  for(int i = 0; i < size; i ++)
    cout << A[i] << " ";
}

int main()
{
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  cout << "given array is \n";
  printArray(arr, arr_size);

  mergeSort(arr, 0, arr_size - 1);

  cout << "\nSorted array is \n";
  printArray(arr, arr_size);

  return 0; 

}
