def main():
  nums1 = list(map(int, input().split()))
  nums2 = list(map(int, input().split()))
  print(maxDotProduct(nums1, nums2))

def maxDotProduct(nums1: list[int], nums2: list[int]) -> int:
  n1, n2 = len(nums1), len(nums2)
  dp = {}
  def helper(i: int, j: int) -> int:
    if (i, j) in dp:
      return dp[(i, j)]
    if i == n1 or j == n2:
      return float('-inf')
    prod = nums1[i] * nums2[j]
    dp[(i, j)] = max(
      prod,
      prod + helper(i + 1, j + 1),
      helper(i + 1, j),
      helper(i, j + 1)
    )
    return dp[(i, j)]
  return helper(0, 0)

if __name__ == '__main__':
  main()