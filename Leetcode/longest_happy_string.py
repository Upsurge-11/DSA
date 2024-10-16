import heapq

def main():
  a, b, c = map(int, input().split())
  print(longestDiverseString(a, b, c))

def longestDiverseString(a: int, b: int, c: int) -> str:
  heap = []
  if a > 0:
    heapq.heappush(heap, (-a, 'a'))
  if b > 0:
    heapq.heappush(heap, (-b, 'b'))
  if c > 0:
    heapq.heappush(heap, (-c, 'c'))
  ans = ""
  while heap:
    num, char = heapq.heappop(heap)
    if len(ans) >= 2 and ans[-1] == ans[-2] == char:
      if not heap:
        return ans
      num2, char2 = heapq.heappop(heap)
      ans += char2
      num2 += 1
      if num2 < 0:
        heapq.heappush(heap, (num2, char2))
      heapq.heappush(heap, (num, char))
    else:
      ans += char
      num += 1
      if num < 0:
        heapq.heappush(heap, (num, char))
  return ans

if __name__ == '__main__':
  main()