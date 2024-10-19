def main():
  n, k = map(int, input().split())
  print(findKthBit(n, k))

def findKthBit(n: int, k: int) -> str:
  return findNString(n)[k - 1]

def findNString(n: int) -> str:
  if n == 1:
    return '0'
  inverse = ''.join(reversed(inverseString(findNString(n - 1))))
  return findNString(n - 1) + '1' + inverse

def inverseString(s: str) -> str:
  n = len(s)
  ans = ''
  for i in range(n):
    if s[i] == '0':
      ans += '1'
    else:
      ans += '0'
  return ans

if __name__ == '__main__':
  main()