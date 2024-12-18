function countingSort(arr: number[]): number[] {
  const maxVal = Math.max(arr);
  const countArray = new Array(maxVal + 1).fill(0);

  // count occurrences of each element
  for(let i = 0; i < arr.length; i++) {
    countArray[arr[i]]++;
  }

  // modify count array to store actual positions of elements 
  for(let i = 1; i <= maxVal; i++) {
    countArray[i] += countArray[i - 1];
  }

  const output = new Array(arr.length);
  for(let i = arr.length - 1; i >= 0; i--) {
    output[countArray[arr[i]] - 1] = arr[i];
    countArray[arr[i]]--;
  }
  return output;
}

// example usage
const numbers = [64, 34, 25, 22, 11, 90];
const sortedNumbers = countingSort(numbers);
console.log(sortedNumbers);

