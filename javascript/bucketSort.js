function bucketSort(array) {
  const bucketSize = 5;
  const maxValue = Math.max(array);
  const minValue = Math.min(array);

  const bucketCount = Math.floor((maxValue - minValue) / bucketSize) + 1;
  const buckets = Array.from({length : bucketCount }, () => []);

  // insert elements into buckets
  for(let i = 0; i < array.length; i++) {
    const bucketIndex = Math.floor((array[i] - minValue) / bucketSize);
    buckets[bucketIndex].push(array[i]);
  }
  // sort individual buckets
  for(let i = 0; i < bucketCount; i++) {
    buckets[i].sort((a, b) => a - b);
  }
  // concatenate sorted buckets
  let index = 0;
  for(let i = 0; i < bucketCount; i++) {
    for(let j = 0; j < buckets[i].length; j++) {
      array[index++] = buckets[i][j];
    }
  }
}

// example usage
const array = [170, 45, 75, 90, 802, 24, 2, 66];
bucketSort(array);
console.log(array);
