// time complexity; O(n^2)
// space complexity; O(1)

public class SelectionSort
  {
    public static void selectionSort(int[] arr)
    {
      int n = arr.length;
      // one by one move boundary of unsorted subarray 
      for(int i = 0; i < n - 1; ++i)
        {
          // find min element in unsorted array
          int min_idx = i;
          for(int j = i + 1; j < n; j ++)
            if(arr[j] < arr[min_idx])
              min_idx = j;
          // swap found min element with first element
          int temp = arr[min_idx];
          arr[min_idx] = arr[i];
          arr[i] = temp;
        }
    }
  }
