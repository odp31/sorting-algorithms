function quickSort(arr: number[]): number[] {
  if(arr.length <= 1) {
    return arr;
  }

  const pivotIndex = Math.floor(arr.length / 2);
  const pivot = arr[pivotIndex];

  const left = arr.filter(x => x < pivot);
  const middle = arr.filter(x => x === pivot);
  const right = arr.filter(x => x > pivot);

  return [quickSort(left), quickSort(middle), quickSort(right)];
}

// example usage
const numbers = [64, 34, 25, 12, 22, 11, 90];
const sortedNumbers = quickSort(numbers);
console.log(sortedNumbers);

