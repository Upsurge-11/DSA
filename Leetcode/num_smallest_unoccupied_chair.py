import heapq

def main():
  times = [list(map(int, input().split())) for _ in range(int(input()))]
  targetFriend = int(input())
  print(smallestChair(times, targetFriend))

def smallestChair(times: list[list[int]], targetFriend: int) -> int:
  n = len(times)
  arrivals = [(times[i][0], i) for i in range(n)]
  arrivals.sort()
  
  availableChairs = list(range(n))
  heapq.heapify(availableChairs)

  leavingQueue = []
  for arrivalTime, friendIndex in arrivals:
    while leavingQueue and leavingQueue[0][0] <= arrivalTime:
      heapq.heappush(availableChairs, heapq.heappop(leavingQueue)[1])
    chair = heapq.heappop(availableChairs)
    if friendIndex == targetFriend:
      return chair
    heapq.heappush(leavingQueue, (times[friendIndex][1], chair))
  return -1


if __name__ == '__main__':
  main()