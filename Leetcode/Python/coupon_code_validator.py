def main():
  code = list(map(str, input().split()))
  businessLine = list(map(str, input().split()))
  isActive = list(map(bool, input().split()))
  print(validateCoupons(code, businessLine, isActive))

def validateCoupons(code: list[str], businessLine: list[str], isActive: list[bool]) -> list[str]:
  result = []
  n = len(code)
  priority = {
    "electronics": 0,
    "grocery": 1,
    "pharmacy": 2,
    "restaurant": 3
  }
  def is_valid_code(s: str) -> bool:
    return len(s) > 0 and all(c.isalnum() or c == '_' for c in s)
  for i in range(n):
    if isActive[i] and is_valid_code(code[i]) and businessLine[i] in priority:
      result.append((priority[businessLine[i]], code[i]))
  result.sort()
  return [coupon for _, coupon in result]

if __name__ == '__main__':
  main()