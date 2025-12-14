def main():
  corridor = input()
  print(numberOfWays(corridor))

def numberOfWays(corridor: str) -> int:
  MOD = 10**9 + 7
  position = []
  
  for i, c in enumerate(corridor):
    if c == 'S':
      position.append(i)

  if len(position) % 2 != 0 or len(position) == 0:
    return 0
  
  res = 1
  for i in range(2, len(position), 2):
    res = (res * (position[i] - position[i - 1])) % MOD
  
  return res

if __name__ == '__main__':
  main()