def main():
  s = input()
  print(hasSameDigits(s))

def func(s: str) -> str:
  digits = [int(c) for c in s if c.isdigit()]
  ans = []
  for i in range(0, len(digits)):
    if i < len(digits) - 1:
      summed = digits[i] + digits[i+1]
      ans.append(summed % 10)
  return ''.join(str(c) for c in ans)

def hasSameDigits(s: str) -> bool:
  temp = s
  while len(temp) != 2:
    temp = func(temp)
  return temp[0] == temp[1]

if __name__ == '__main__':
  main()