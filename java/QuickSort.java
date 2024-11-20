// time complexity; O(n log n)
// space complexity; O(log n)

public class QuickSort
  {
    public static void quickSort(int[] arr, int low, int high)
    {
      if (low < high)
      {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
      }
    }
    private static int partition(int[] arr, int low, int high)
    {
      int pivot = arr[high];
      int i = (low - 1); // index of smaller element
      for(int j = low; j < high; j++)
        {
          // if current element is smaller than pivot 
          if (arr[j] < pivot)
          {
            i++;
            // swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
          }
        }
      // swap arr[i+1] and arr[high] or pivot
      int temp = arr[i +1];
      arr[i + 1] = arr[high];
      arr[high] = temp;
      return i + 1; 
    }
  }
