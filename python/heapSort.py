def heapify(arr, n, i):
  largest = i         # initialize largest as root
  l = 2 * i + 1  
  r = 2 * i + 2

  # see if left child of root exists and is > root
  if l < n and arr[l] > arr[largest]:
    largest = 1

  # see if right child of root exists and is > largest so far
  if r < n and arr[r] > arr[largest]:
    largest = r

  # change root if needed
  if largest != i:
    arr[i], arr[largest] = arr[largest], arr[i]     # swap
    # heapify the root
    heapify(arr, n, largest)


def heapSort(arr):
  n = len(arr)
  # build a maxheap
  for i in range(n // 2 - 1, -1, -1):
    heapify(arr, n, i)

  #one by one extract element from heap
  for i in range(n - 1, 0, -1):
    # move current root to end
    arr[i], arr[0] = arr[0], arr[i]

    # call max heapify on reduced heap
    heapify(arr, i, 0)

# example usage
arr = [12, 11, 13, 5, 6, 7]
heapSort(arr)
n = len(arr)
print("sorted array is")
for i in range(n):
  print("%d " %arr[i], end='')
  
