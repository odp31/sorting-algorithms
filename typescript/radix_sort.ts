function radixSort(arr: number[]): number[] {
  const maxVal = Math.max(arr);
  let exp = 1;

  while(Math.floor(maxVal / exp) > 0) {
    countingSort(arr, exp);
    exp *= 10;
  }
  return arr;
}

function countingSort(arr: number[], exp: number): void {
  const n = arr.length;
  const output = new Array(n);
  const count = new Array(10).fill(0);

  // store count of occurrences in count[]
  for(let i = 0; i < n; i++) {
    const index = Math.floor((arr[i] / exp) % 10);
    count[index]++;
  }

  for(let i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }
  for(let i = n - 1; i >= 0; i--) {
    const index = Math.floor((arr[i] / exp) % 10);
    output[count[index] - 1] = arr[i];
    count[index]--;
  }
  for(let i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

// example usage
const numbers = [64, 34, 25, 12, 22, 11, 90];
const sortedNumbers = radixSort(numbers);
console.log(sortedNumbers);
