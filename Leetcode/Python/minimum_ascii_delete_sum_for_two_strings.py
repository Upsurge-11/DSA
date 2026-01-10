def main():
  s1 = input().strip()
  s2 = input().strip()
  print(minimumDeleteSum(s1, s2))

def minimumDeleteSum(s1: str, s2: str) -> int:
  dp = {}
  def lcs(n: int, m: int) -> int:
    if n == 0 or m == 0:
      return 0
    if (n, m) in dp:
      return dp[(n, m)]
    if s1[n - 1] == s2[m - 1]:
      dp[(n, m)] = ord(s1[n - 1]) + lcs(n - 1, m - 1)
    else:
      dp[(n, m)] = max(lcs(n - 1, m), lcs(n, m - 1))
    return dp[(n, m)]
  
  total_sum = sum(ord(c) for c in s1) + sum(ord(c) for c in s2)
  lcs_sum = lcs(len(s1), len(s2))
  return total_sum - (2 * lcs_sum)

if __name__ == '__main__':
  main()