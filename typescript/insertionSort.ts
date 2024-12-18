function insertionSort(arr: number[]): number[] {
  for(let i = 1; i < arr.length; i++) {
    let key = arr[i];
    let j = i - 1;

    while(j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
  return arr;
}

// example usage
const numbers = [64, 34, 25, 12, 22, 11, 90];
const sortedNumbers = insertionSort(numbers);
console.log(sortedNumbers);

