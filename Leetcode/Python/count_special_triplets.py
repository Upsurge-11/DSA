def main():
  nums = list(map(int, input().split()))
  print(specialTriplets(nums))

def specialTriplets(nums: list[int]) -> int:
  MOD = 10**9 + 7
  freq_map = {}
  left_map = {}
  for num in nums:
    freq_map[num] = freq_map.get(num, 0) + 1
  count = 0
  for num in nums:
    target = num * 2
    left_count = left_map.get(target, 0)
    left_map[num] = left_map.get(num, 0) + 1
    right_count = freq_map.get(target, 0) - left_map.get(target, 0)
    count = (count + (left_count * right_count)) % MOD
  return count

if __name__ == '__main__':
  main()