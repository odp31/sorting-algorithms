public class CountingSort {
  public static void sort(int[] arr) {
    // find max element in array
    int max = arr[0];
    for(int i = 1; i < arr.length; i++) {
      if(arr[i] > max) {
        max = arr[i];
      }
    }
    // create count array to store count of each element
    int[] count = new int[max + 1];
    // store count of each element in count array
    for(int i = 0; i < arr.length; i++) {
      count[arr[i]]++;
    }
    // modify count array to store actual position of element 
    for(int i = 1; i <= max; i++) {
      count[i] += count[i - 1];
    }
    // build sorted array
    int[] output = new int[arr.length];
    for(int i = arr.length - 1; i >= 0; i--) {
      output[count[arr[i]] - 1] = arr[i];
      count[arr[i]]--;
    }
    // copy sorted elements back to original array
    System.arraycopy(output, 0, arr, 0, arr.length);
  }
  public static void main(String[] args) {
    int[] arr = {64, 25, 12, 22, 11};
    sort(arr);
    System.out.println("sorted array: ");
    for(int num: arr) {
      System.out.print(num + " ");
    }
  }
}
