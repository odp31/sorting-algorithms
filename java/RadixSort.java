// noncomparative sorting algorithm that sorts numbers digit by digit starting from the least
// significant digit to the most significant digit 

public class RadixSort {
  public static void radixSort(int[] arr) {
    int max = getMax(arr, arr.length);

    for(int exp = 1; max / exp > 0; exp *= 10) {
      countSort(arr, n, exp);
    }
  }
  static int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++)
      if(arr[i] > max)
        max = arr[i];
    return max;
  }
  // function to do coutning sort of arr[] according to digit represetned by exponent
  static void countSort(int arr[], int n, int exp) {
    int output[] = new int[n];
    int i;
    int count[] = new int[10];
    Arrays.fill(count, 0);

    for(i = 0; i < n; i++)
      count[(arr[i] / exp) % 10]++;

    for(i = 1; i < 10; i++)
      count[i] += count[i - 1];

    // build output array
    for(i = n - 1; i >= 0; i--) {
      output[count[(arr[i] / exp) % 10] - 1] = arr[i];
      count[(arr[i] / exp) % 10]--;
    }
    for(i = 0; i < n; i++)
      arr[i] = output[i];
  }
}
