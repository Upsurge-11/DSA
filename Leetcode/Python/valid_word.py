def main():
  word = input()
  print(isValid(word))

def isValid(word: str) -> bool:
  has_vowel = False
  has_consonant = False
  if len(word) < 3:
    return False
  for c in word:
    if not c.isalnum():
      return False
    if c.lower() in 'aeiou':
      has_vowel = True
    elif c.lower() in 'bcdfghjklmnpqrstvwxyz':
      has_consonant = True
  return has_vowel and has_consonant

if __name__ == '__main__':
  main()