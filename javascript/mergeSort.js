function mergeSort(arr)
{
  if(arr.length <= 1)
  {
    return arr;
  }
  const mid = Math.floor(arr.length / 2);
  const leftHalf = arr.slice(0, mid);
  const rightHalf = arr.slice(mid);

  return merge(mergeSort(leftHalf), mergeSort(rightHalf));
}

function merge(left, right)
{
  const merged = [];
  let i = 0, j = 0;
  while(i < left.length && i < right.length)
    {
      if(left[i] < right[j])
      {
        merged.push(left[i]);
        i++;
      }
      else
      {
        merged.push(right[j]);
        j++;
      }
    }
  return merged.concat(left.slice(i)).concat(right.slice(j));
}

