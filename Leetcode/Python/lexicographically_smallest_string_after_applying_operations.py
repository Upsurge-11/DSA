def main():
  s = input()
  a = int(input())
  b = int(input())
  print(findLexSmallestString(s, a, b))

def findLexSmallestString(s: str, a: int, b: int) -> str:
  incremented = {str(n):str((n + a) % 10) for n in range(10)}
  def add_operation(s: str) -> str:
    res = ""
    for i in range(len(s)):
      res += s[i] if i % 2 == 0 else incremented[s[i]]
    return res
  
  def rotate_operation(s: str) -> str:
    return s[-b:] + s[:-b]
  
  seen = set()
  
  def dfs(s: str) -> None:
    if s in seen:
      return
    seen.add(s)
    dfs(add_operation(s))
    dfs(rotate_operation(s))
    return
  
  dfs(s)
  return min(seen)

if __name__ == '__main__':
  main()