// sorting algorithm that uses a heap data structure to sort elements
// involves 2 main steps:
// 1. building a max heap (largest element is at the root)
// 2. heapify; repeatedly remove max element from heap and replace it with the last element
// then heapify the reduced heap
// time complexity: O(n log n) 
public class HeapSort {
  public void sort(int[] arr) {
    int n = arr.length;
    // build heap (rearrange array)
    for(int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    // one by one extract element from heap
    for(int i = n - 1; i > 0; i--) {
      // move current root to end
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp; 

      // call max heapify on the reduced heap
      heapify(arr, i, 0);
    }
  }
  // heapify a subtree rooted with node i wich is an index in arr[]; n is size of heap
  void heapify(int arr[], int n, int i) {
    int largest = i;             // initalize largest as root
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // if left child is > root
    if(l < n && arr[l] > arr[largest])
      largest = l;

    // if right child > largest so far
    if(r < n && arr[r] > arr[largest])
      largest = r;

    // if largest is not root
    if(largest != i) {
      int swap = arr[i];
      arr[i] = arr[largest];
      arr[largest] = swap;

      // recursively heapify affected subtree
      heapify(arr, n, largest);
    }
  }
}
