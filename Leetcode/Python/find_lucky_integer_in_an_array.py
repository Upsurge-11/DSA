from collections import Counter


def main():
  arr = list(map(int, input().split()))
  print(findLucky(arr))

def findLucky(arr: list[int]) -> int:
  freq = Counter(arr)
  for num in sorted(freq.keys(), reverse=True):
    if freq[num] == num:
      return num
  return -1

if __name__ == '__main__':
  main()