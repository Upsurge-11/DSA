def main():
  s = input().strip()
  print(countPalindromicSubsequence(s))

def countPalindromicSubsequence(s: str) -> int:
  res = 0
  for c in set(s):
    first = s.find(c)
    last = s.rfind(c)
    if last - first > 1:
      unique_chars = set(s[first + 1:last])
      res += len(unique_chars)
  return res

if __name__ == '__main__':
  main()