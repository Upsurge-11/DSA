def main():
  k = int(input())
  print(kthCharacter(k))

def kthCharacter(k: int) -> str:
  alice = ["a"]
  while len(alice) < k:
    for i in range(len(alice)):
      next_char = chr(ord('a') + ((ord(alice[i]) - ord('a') + 1) % 26))
      alice.append(next_char)
  return alice[k - 1]

if __name__ == '__main__':
  main()