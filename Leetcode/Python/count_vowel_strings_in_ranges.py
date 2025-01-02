def main():
  words = [x for x in input().split()]
  queries = [list(map(int, input().split())) for _ in range(int(input()))]
  print(vowelStrings(words, queries))

def isVowel(c: str) -> bool:
  return c in 'aeiou'

def vowelStrings(words: list[str], queries: list[list[int]]) -> list[int]:
  v = [1 if isVowel(word[0]) and isVowel(word[-1]) else 0 for word in words]
  pref = [0] * len(v)
  pref[0] = v[0]
  for i in range(1, len(v)):
    pref[i] = pref[i - 1] + v[i]
  ans = []
  for l, r in queries:
    ans.append(pref[r] if l == 0 else pref[r] - pref[l - 1])
  return ans

if __name__ == '__main__':
  main()