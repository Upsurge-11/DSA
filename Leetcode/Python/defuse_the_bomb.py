def main():
  code = [int(x) for x in input().split()]
  k = int(input())
  print(decrypt(code, k))

def decrypt(code: list[int], k: int) -> list[int]:
  n = len(code)
  ans = [0] * n
  if k == 0:
    return ans
  for i in range(n):
    if k > 0:
      for j in range(i+1, i+1+k):
        ans[i] += code[j % n]
    elif k < 0:
      for j in range(i-1, i-1-abs(k), -1):
        ans[i] += code[j % n]
  return ans

if __name__ == '__main__':
  main()