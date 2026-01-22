def main():
  nums = list(map(int, input().split()))
  print(minimumPairRemoval(nums))

def minimumPairRemoval(nums: list[int]) -> int:
  operations = 0
  def minPair(nums: list[int]) -> int:
    min_sum = float('inf')
    pos = -1
    for i in range(len(nums) - 1):
      if nums[i] + nums[i + 1] < min_sum:
        min_sum = nums[i] + nums[i + 1]
        pos = i
    return pos
  def mergePair(nums: list[int], pos: int) -> None:
    nums[pos] += nums[pos + 1]
    del nums[pos + 1]
  while nums != sorted(nums):
    mergePair(nums, minPair(nums))
    operations += 1
  return operations

if __name__ == '__main__':
  main()