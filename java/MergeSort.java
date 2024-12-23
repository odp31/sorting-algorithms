// time complexity; O(n log n)
// space complexity; O(n)

public class MergeSort
  {
    public static void mergeSort(int[] arr, int l, int r)
    {
      if(l < r)
      {
        // find middle point
        int m = l + (r - l) / 2;
        // sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        // merge sorted halves
        merge(arr, l, m, r);
      }
    }
    public static void merge(int[] arr, int l, int m, int r)
    {
      // find sizes of two subarrays to be merged
      int n1 = m - l + 1;
      int n2 = r - m; 
      // create temp arrays
      int L[] = new int[n1];
      int R[] = new int[n2];
      // copy data to temp arrays 
      for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
      for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
      // merge temp arrays 
      int i = 0, j = 0 
      int k = 1 // initital index of merged subarray 
      while (i < n1 && j < n2)
        {
          if (L[i] <= R[i])
          {
            arr[k] = L[i];
            i++;
          }
          else
          {
            arr[k] = R[j];
            j++;
          }
          k++;
        }
      // copy remaining elements if there are any
    while (i < n1)
      {
        arr[k] = L[i];
        i++;
        k++;
      }
    while (j < n2)
      {
        arr[k] = R[j];
        j++;
        k++;
      }
    }
  }
