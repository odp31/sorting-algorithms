// sorting algorithm that distributes elements into a fixed number of buckets
// each bucket is then sorted inidvidually and the sorted buckets are concatenated
// to produce final sorted array 


import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class BucketSort {
  public static void bucketSort(int[] arr, int n) {
    // find max value and min value
    int maxVal = arr[0], minVal= arr[0];
    for(int i = 1; i < n; i++) {
      maxVal = Math.max(maxVal, arr[i]);
      minVal = Math.min(minVal, arr[i]);
    }
    // calculate range and number of buckets
    int range = maxVal - minVal + 1;
    int numBuckets = (int) Math.sqrt(n);
    List<List<Integer>> buckets = new ArrayList<>(numBuckets);

    // initialize buckets
    for(int i = 0; i < numBuckets; i++) {
      buckets.add(new ArrayList<>());
    }
    // distribute elements into buckets
    for(int i = 0; i < n; i++) {
      int bucketIndex = (int) (((arr[i] - minVal) * (numBuckets - 1)) / range);
      buckets.get(bucketIndex).add(arr[i]);
    }
    // sort each bucket individually
    for(List<Integer> bucket: buckets) {
      Collections.sort(bucket);
    }
    // concatenate sorted buckets
    int index = 0;
    for(List<Integer> bucket : buckets) {
      for(int num: bucket) {
        arr[index++] = num;
      }
    }
  }
}
