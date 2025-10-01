def main():
  numBottles = int(input())
  numExchange = int(input())
  print(numWaterBottles(numBottles, numExchange))

def numWaterBottles(numBottles: int, numExchange: int) -> int:
  totalDrank = numBottles
  emptyBottles = numBottles

  while emptyBottles >= numExchange:
    newBottles = emptyBottles // numExchange
    totalDrank += newBottles
    emptyBottles = emptyBottles % numExchange + newBottles

  return totalDrank

if __name__ == '__main__':
  main()