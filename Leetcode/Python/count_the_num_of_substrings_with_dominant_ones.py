def main():
  s = input().strip()
  print(numberOfSubstrings(s))

def numberOfSubstrings(s: str) -> int:
  n = len(s)
  next_zero = [n] * (n)
  for i in range(n-2, -1, -1):
    if s[i+1] == '0':
      next_zero[i] = i + 1
    else:
      next_zero[i] = next_zero[i + 1]
  res = 0
  for l in range(n):
    zeroes = 1 if s[l] == "0" else 0
    r = l
    while zeroes * zeroes <= n:
      next_z = next_zero[r]
      ones = (next_z - l) - zeroes
      if ones >= zeroes * zeroes:
        res += min(next_z - r, ones - (zeroes * zeroes) + 1)
      r = next_z
      zeroes += 1
      if r == n:
        break
  return res

if __name__ == '__main__':
  main()