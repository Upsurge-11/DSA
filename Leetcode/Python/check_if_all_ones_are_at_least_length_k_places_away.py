def main():
  nums = list(map(int, input().split()))
  k = int(input())
  print(kLengthApart(nums, k))

def kLengthApart(nums: list[int], k: int) -> bool:
  first_one_found = False
  last_one_index = -1
  for i in range(len(nums)):
    if nums[i] == 1:
      if not first_one_found:
        first_one_found = True
      else:
        if i - last_one_index - 1 < k:
          return False
      last_one_index = i
  return True

if __name__ == '__main__':
  main()