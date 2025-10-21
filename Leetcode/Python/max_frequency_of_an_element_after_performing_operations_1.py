def main():
  nums = list(map(int, input().split()))
  k = int(input())
  numOperations = int(input())
  print(maxFrequency(nums, k, numOperations))

def maxFrequency(nums: list[int], k: int, numOperations: int) -> int:
  ans = 0
  mini = min(nums)
  maxi = max(nums)
  freq = [0] * (maxi + 1)
  for num in nums:
    freq[num] += 1
  
  for i in range(1, len(freq)):
    freq[i] += freq[i - 1]
  
  for curr in range(mini, maxi + 1):
    left = max(mini, curr - k)
    right = min(maxi, curr + k)
    f = freq[curr] - freq[curr-1]
    extra_freq = min(numOperations, freq[right] - freq[left - 1] - f)
    ans = max(ans, f + extra_freq)

  return ans

if __name__ == '__main__':
  main()