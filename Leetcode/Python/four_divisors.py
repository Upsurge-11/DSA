def main():
  nums = list(map(int, input().split()))
  print(sumFourDivisors(nums))

def sumFourDivisors(nums: list[int]) -> int:
  ans = 0
  def isPrime(n: int) -> bool:
    if n < 2:
      return False
    for i in range(2, int(n ** 0.5) + 1):
      if n % i == 0:
        return False
    return True
  def sumOne(n: int) -> int:
    p = round(n ** (1/3))
    if p ** 3 == n and isPrime(p):
      return 1 + p + p * p + n
    for i in range(2, int(n ** 0.5) + 1):
      if n % i == 0:
        a, b = i, n // i
        if a != b and isPrime(a) and isPrime(b):
          return 1 + a + b + n
        return -1
    return -1
  for n in nums:
    val = sumOne(n)
    if val != -1:
      ans += val
  return ans

if __name__ == '__main__':
  main()