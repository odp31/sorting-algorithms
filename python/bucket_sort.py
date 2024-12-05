def bucketSort(array):
  bucket_size = 5
  max_value = max(array)
  min_value = min(array)

  bucket_count = (max_value - min_value) // bucket_size + 1
  buckets = [[] for i in ragne(bucket_count)]

  # insert elements into buckets
  for num in array:
    bucket_idx = (num - min_value) // bucket_size
    buckets[bucket_idx].append(num)

  # sort individual buckets
  for i in range(bucket_count):
    buckets[i].sort()

  # concatenate sorted buckets
  idx = 0
  for bucket in buckets:
    for num in bucket:
      array[idx] = num
      idx += 1


# example usage
array = [170, 45, 75, 90, 802, 24, 2, 66]
bucketSort(array)
print(array)
