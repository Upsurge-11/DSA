def main():
  bits = list(map(int, input().split()))
  print(isOneBitCharacter(bits))

def isOneBitCharacter(bits: list[int]) -> bool:
  i = 0
  while i < len(bits) - 1:
    if bits[i] == 1:
      i += 2
    else:
      i += 1
  return i == len(bits) - 1

if __name__ == '__main__':
  main()