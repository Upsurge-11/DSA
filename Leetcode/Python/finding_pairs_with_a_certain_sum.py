from collections import Counter


class FindSumPairs:
  nums1: list[int]
  nums2: list[int]
  def __init__(self, nums1: list[int], nums2: list[int]):
    self.nums1 = nums1
    self.nums2 = nums2
    self.freq = Counter(nums2)

  def add(self, index: int, val: int) -> None:
    old_val = self.nums2[index]
    self.nums2[index] += val
    new_val = self.nums2[index]
    if old_val != new_val:
      self.freq[old_val] -= 1
      if self.freq[old_val] == 0:
        del self.freq[old_val]
      self.freq[new_val] += 1

  def count(self, tot: int) -> int:
    ans = 0
    for num in self.nums1:
      ans += self.freq[tot - num]
    return ans

def main():
  nums1 = list(map(int, input().split()))
  nums2 = list(map(int, input().split()))
  obj = FindSumPairs(nums1, nums2)
  val = int(input())
  obj.add(0, val)
  tot = int(input())
  result = obj.count(tot)
  print(result)

if __name__ == '__main__':
  main()