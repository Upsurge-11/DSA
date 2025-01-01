def main():
  s = input()
  print(maxScore(s))

def maxScore(s : str) -> int:
  total_zeros = s.count('0')
  ans, zeros, n = -1, 0, len(s)
  for i in range(1, n):
    if s[i - 1] == '0':
      zeros += 1
      total_zeros -= 1
    ans = max(ans, zeros + (n - total_zeros - i))
  return ans

if __name__ == '__main__':
  main()