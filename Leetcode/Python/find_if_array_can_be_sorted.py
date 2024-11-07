def main():
  nums = [int(x) for x in input().split()]
  print(canSortArray(nums))

def canSortArray(nums: list[int]) -> bool:
  previous_max = current_min = current_max = previous_bitcount = 0
  for num in nums:
    current_bitcount = bin(num).count('1')
    if current_bitcount == previous_bitcount:
      current_min = min(current_min, num)
      current_max = max(current_max, num)
    elif current_min < previous_max:
      return False
    else:
      previous_max = current_max
      previous_bitcount = current_bitcount
      current_min = current_max = num
  return current_min >= previous_max

if __name__ == '__main__':
  main()