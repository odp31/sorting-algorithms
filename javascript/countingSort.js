function countingSort(arr) {
  const max = Math.max(arr);
  const count = new Array(max + 1).fill(0);

  for(const num of arr) {
    count[num]++;
  }
  for(let i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }
  // build sorted array
  const output = new Array(arr.length);
  for(let i = arr.length - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }
  return output;
}

// example usage
const arr = [64, 25, 12, 22, 11];
const sortedArr = countingSort(arr);
console.log(sortedArr);

