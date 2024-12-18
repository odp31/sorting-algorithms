class HeapSort {
  public heapSort(arr: number[]): void {
    const n = arr.length;

    // build a max heap
    for(let i = Math.floor(n / 2) - 1; i >= 0; i--) {
      this.heapify(arr, n, i);
    }

    // extract elements one by one
    for(let i = n - 1; i >= 0; i--) {
      [arr[0], arr[i]] = [arr[i], arr[0]];
      this.heapify(arr, i, 0);
    }
  }

  private heapify(arr: number[], n: number, i: number): void {
    let largest = i;
    const left = 2 * i + 1;
    const right = 2 * i + 2;

    // if left child > root
    if(left < n && arr[left] > arr[largest]) {
      largest = left;
    }

    // if right child > largest
    if(right < n && arr[right] > arr[largest]) {
      largest = right;
    }

    // if largest is not root
    if(largest !== i) {
      [arr[i], arr[largest]] = [arr[largest], arr[i]];
      this.heapify(arr, n, largest);
    }
  }
}
