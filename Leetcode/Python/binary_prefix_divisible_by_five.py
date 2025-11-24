def main():
  nums = list(map(int, input().split()))
  print(prefixesDivBy5(nums))

def prefixesDivBy5(nums: list[int]) -> list[bool]:
  result = []
  bin_str = ''
  for num in nums:
    bin_str += str(num)
    result.append(int(bin_str, 2) % 5 == 0)
  return result

if __name__ == '__main__':
  main()