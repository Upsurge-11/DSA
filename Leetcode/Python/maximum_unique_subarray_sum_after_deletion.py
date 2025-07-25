def main():
  nums = list(map(int, input().split()))
  print(maxSum(nums))

def maxSum(nums: list[int]) -> int:
  unique_arr = list(set(nums))
  unique_arr.sort(reverse=True)
  max_sum = 0
  for i in range(len(unique_arr)):
    if unique_arr[i] < 0 and i > 0:
      break
    max_sum += unique_arr[i]
  return max_sum

if __name__ == '__main__':
  main()