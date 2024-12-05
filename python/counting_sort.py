def counting_sort(arr):
  max_element = max(arr)

  # create count array to store count of each element
  count = [0] * (max_element + 1)

  # store count of each element in count array 
  for num in arr:
    count[num] += 1

  # modify count array to store actual position of element
  for i in range(1, max_element + 1):
    count[i] += count[i - 1]

  # build sorted array
  output = [0] * len(arr)
  for num in reversed(arr):
    output[count[num] - 1] = num
    count[num] -= 1

  return output

# example usage
arr = [64, 25, 12, 22, 11]
sorted_arr = counting_sort(arr)
print(sorted_arr)

