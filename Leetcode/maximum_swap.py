def main():
  num = int(input())
  print(maximumSwap(num))

def maximumSwap(num: int) -> int:
  digits = list(str(num))
  max_index, swap_index1, swap_index2 = -1, -1, -1
  for i in range(len(digits)-1, -1, -1):
    if max_index == -1 or digits[i] > digits[max_index]:
      max_index = i
    elif digits[i] < digits[max_index]:
      swap_index1, swap_index2 = i, max_index
  if swap_index1 != -1 and swap_index2 != -1:
    digits[swap_index1], digits[swap_index2] = digits[swap_index2], digits[swap_index1]
  return int(''.join(digits))

if __name__ == '__main__':
  main()