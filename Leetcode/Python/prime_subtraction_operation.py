def main():
  nums = [int(x) for x in input().split()]
  print(primeSubOperation(nums))

def primeSubOperation(nums: list[int]) -> bool:
  def is_prime(n: int) -> bool:
    if n < 2:
      return False
    for i in range(2, int(n ** 0.5) + 1):
      if n % i == 0:
        return False
    return True
  prev = 0
  for n in nums:
    upper_bound = n - prev
    largest_prime_num = 0
    for i in reversed(range(2, upper_bound)):
      if is_prime(i):
        largest_prime_num = i
        break
    if n - largest_prime_num <= prev:
      return False
    prev = n - largest_prime_num
  return True

if __name__ == '__main__':
  main()