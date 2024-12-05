function heapify(arr, n, i) {
  let largest = i;
  let left = 2 * i + 1;
  let right = 2 * i + 2;

  // if left child > root
  if(left < n && arr[left] > arr[largest])
    largest = left;

  // if right child > largest so far
  if(right < n && arr[right] > arr[largest])
    largest = right;

  // if largest is not root
  if(largest != i) {
    [arr[i], arr[largest]] = [arr[largest], arr[i]];
    //recursively heapify affected subtree
    heapify(arr, n, largest);
  }
}

function heapSort(arr) {
  const n = arr.length;
  // build heap (rearrange array)
  for(let i = Math.floor(n / 2) - 1; i >= 0; i--)
    heapify(arr, n, i)

  // one by one extract element from heap
  for(let i = n - 1; i > 0; i--) {
    [arr[0], arr[i]] = [arr[i], arr[0]];
    // call max heapify on reduced heap
    heapify(arr, i, 0);
  }
}

// example usage
const arr = [12, 11, 13, 5, 6, 7];
heapSort(arr);

console.log("sorted array is:");
for(let i = 0; i < arr.length; i++) {
  console.log(arr[i]);
}
