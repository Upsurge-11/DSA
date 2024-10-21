def main():
  s = input()
  print(maxUniqueSplit(s))

def maxUniqueSplit(s: str) -> int:
  memo=set()
  max_count = 0
  def func(i, cnt, s):
    nonlocal max_count
    if len(s) - i <= max_count - cnt: return
    if  i >= len(s):
      max_count = max(max_count, cnt)
      return
    curr = ""
    for j in range(i, len(s)):
        curr+=s[j]
        if curr in memo: continue
        memo.add(curr)
        func(j+1, cnt+1, s)
        memo.remove(curr)
  func(0, 0, s)
  return max_count

if __name__ == '__main__':
  main()