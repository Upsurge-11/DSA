def main():
  sentence = input()
  print(isCircularSentence(sentence))

def isCircularSentence(sentence: str) -> bool:
  sentences = sentence.split()
  if len(sentences) == 1:
    return sentence[0] == sentence[-1]
  for i in range(1, len(sentences)):
    if sentences[i-1][-1] != sentences[i][0]:
      return False
  return sentence[0] == sentence[-1]

if __name__ == '__main__':
  main()