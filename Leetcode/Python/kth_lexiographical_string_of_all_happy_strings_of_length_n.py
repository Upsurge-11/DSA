from itertools import product

def main():
  n = int(input())
  k = int(input())
  print(getHappyString(n, k))

def getHappyString(n: int, k: int) -> str:
  def func(n: int) -> list[str]:
    chars = ['a', 'b', 'c']
    result = []
    for p in product(chars, repeat=n):
      valid = True
      for i in range(1, n):
        if p[i] == p[i-1]:
          valid = False
          break
      if valid:
        result.append(''.join(p))
    return result
  happy_strings = func(n)
  happy_strings.sort()
  if k > len(happy_strings):
    return ''
  return happy_strings[k-1]

if __name__ == '__main__':
  main()