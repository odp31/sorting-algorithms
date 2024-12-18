function bucketSort(arr: number[], bucketSize: number): number[] {
  const maxVal = Math.max(arr);
  const bucketCount = Math.floor(maxVal / bucketSize) + 1;

  const buckets: number[][] = [];
  for(let i = 0; i < bucketCount; i++) {
    buckets.push([]);
  }

  for(let i = 0; i < arr.length; i++) {
    const bucketIdx = Math.floor(arr[i] / bucketSize);
    buckets[bucketIdx].push(arr[i]);
  }
  for(let i = 0; i < bucketCount; i++) {
    buckets[i].sort((a,b) => a - b);
  }
  const sortedArr: number[] = [];
  for(let i = 0; i < bucketCount; i++) {
    sortedArr.push(buckets[i]);
  }
  return sortedArr;
}

// example usage
const numbers = [29, 10, 14, 39, 18, 26, 31, 40];
const sortedNumbers = bucketSort(numbers, 10);
console.log(sortedNumbers);

