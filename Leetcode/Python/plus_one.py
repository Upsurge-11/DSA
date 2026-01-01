def main():
  digits = list(map(int, input().split()))
  print(plusOne(digits))

def plusOne(digits: list[int])-> list[int]:
  num = ""
  for digit in digits:
    num += str(digit)
  num = str(int(num) + 1)
  result = []
  for n in num:
    result.append(int(n))
  return result

if __name__ == '__main__':
  main()