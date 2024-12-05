function countingSort(arr, exp) {
  const n = arr.length;
  const output = new Array(n);
  const count = new Array(10).fill(0);

  // store count of occurrences in coutn[]
  for(let i = 0; i < n; i++) {
    const index = Math.floor(arr[i] / exp) % 10;
    count[index]++;
  }

  for(let i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }
  // build output array
  for(let i = n - 1; i >= 0; i--) {
    const index = Math.floor(arr[i] / exp) % 10;
    output[count[index] - 1] = arr[i];
    count[index]--;
  }

  for(let i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}
function radixSort(arr) {
  const max = Math.max(arr);
  let exp = 1;
  while(Math.floor(max / exp) > 0) {
    countingSort(arr, exp);
    exp*=10;
  }
}
// example usage
const arr = [170, 45, 75, 90, 802, 24, 2, 66];
radixSort(arr);
console.log(arr);
