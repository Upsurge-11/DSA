def main():
  strs = list(map(str, input().split()))
  m, n = map(int, input().split())
  print(findMaxForm(strs, m, n))

def findMaxForm(strs: list[str], m: int, n: int) -> int:
  dp = {(0, 0): 0}
  for s in strs:
    zeros = s.count('0')
    ones = s.count('1')
    new_dp = {}
    for key, value in dp.items():
      prev_zeros, prev_ones = key
      new_zeros = prev_zeros + zeros
      new_ones = prev_ones + ones
      if new_zeros <= m and new_ones <= n:
        if (new_zeros, new_ones) not in dp:
          new_dp[(new_zeros, new_ones)] = value + 1
        elif dp[(new_zeros, new_ones)] < value + 1:
          new_dp[(new_zeros, new_ones)] = value + 1
    dp.update(new_dp)
  return max(dp.values())

if __name__ == '__main__':
  main()