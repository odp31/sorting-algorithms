function selectionSort(arr: number[]): number[] {
  const n = arr.length;

  for(let i = 0; i < n - 1; i++) {
    // find minimum element in unsorted array
    let minIndex = i;
    for(let j = i + 1; j < n; j++)
      if(arr[j] < arr[minIndex])
        minIndex = j;

    // swap found min element with first 
    [arr[minIndex], arr[i]] = [arr[i], arr[minIndex]];
  }
  return arr;
}

// example usage
const numbers = [64, 34, 25, 12, 22, 11, 90];
const sortedNumbers = selectionSort(numbers);
console.log(sortedNumbers);
