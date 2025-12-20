def main():
  strs = list(map(str, input().split()))
  print(minDeletionSize(strs))

def minDeletionSize(strs: list[str]) -> int:
  ans = 0
  n = len(strs)
  m = len(strs[0])

  for j in range(m):
    for i in range(n - 1):
      if strs[i][j] > strs[i + 1][j]:
        ans += 1
        break
  return ans

if __name__ == '__main__':
  main()