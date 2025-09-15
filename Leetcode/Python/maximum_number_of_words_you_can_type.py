def main():
  text = input()
  broken_letters = input()
  print(canBeTypedWords(text, broken_letters))

def canBeTypedWords(text: str, broken_letters: str) -> int:
  broken_set = set(broken_letters)
  words = text.split()
  count = 0

  for word in words:
    if not any(letter in broken_set for letter in word):
      count += 1

  return count

if __name__ == '__main__':
  main()