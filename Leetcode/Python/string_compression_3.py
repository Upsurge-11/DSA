def main():
  word = input()
  print(compressedString(word))

def compressedString(word: str) -> str:
  ans = ''
  index = 0
  c = word[index]
  count = 1
  while index < len(word):
    if index + 1 < len(word) and word[index + 1] == c and count < 9:
      count += 1
    else:
      ans += str(count) + c
      if index + 1 < len(word):
        c = word[index + 1]
        count = 1
    index += 1
  return ans

if __name__ == '__main__':
  main()