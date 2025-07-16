def main():
  nums = list(map(int, input().split()))
  print(maximumLength(nums))

def maximumLength(nums: list[int]) -> int:
  all_odd = []
  all_even = []
  alternate_odd_even = []
  alternate_even_odd = []
  for num in nums:
    if num % 2 == 0:
      all_even.append(num)
      if len(alternate_even_odd) == 0 or alternate_even_odd[-1] % 2 != 0:
        alternate_even_odd.append(num)
      if len(alternate_odd_even) != 0 and alternate_odd_even[-1] % 2 != 0:
        alternate_odd_even.append(num)
    else:
      all_odd.append(num)
      if len(alternate_odd_even) == 0 or alternate_odd_even[-1] % 2 == 0:
        alternate_odd_even.append(num)
      if len(alternate_even_odd) != 0 and alternate_even_odd[-1] % 2 == 0:
        alternate_even_odd.append(num)

  return max(len(all_odd), len(all_even), len(alternate_odd_even), len(alternate_even_odd))

if __name__ == '__main__':
  main()