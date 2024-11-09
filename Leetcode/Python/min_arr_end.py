def main():
  n, x = [int (x) for x in input().split()]
  print(minEnd(n, x))

# def minEnd(n: int, x: int) -> int:
#   ans = x
#   for _ in range(n-1):
#     ans = (ans+1) | x
#   return ans

def minEnd(n: int, x: int) -> int:
  res = x
  pointer_x = 1
  pointer_n = 1
  while pointer_n < n:
    if pointer_x & x == 0:
      if pointer_n & (n-1):
        res = res | pointer_x
      pointer_n = pointer_n << 1
    pointer_x = pointer_x << 1
  return res

if __name__ == '__main__':
  main()