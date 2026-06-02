def main():
  landStartTime = list(map(int, input().split()))
  landDuration = list(map(int, input().split()))
  waterStartTime = list(map(int, input().split()))
  waterDuration = list(map(int, input().split()))  
  print(earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration))

def earliestFinishTime(landStartTime: list[int], landDuration: list[int], waterStartTime: list[int], waterDuration: list[int]):
  result = float('inf')
  for i in range(len(landStartTime)):
    landFinishTime = landStartTime[i] + landDuration[i]
    for j in range(len(waterStartTime)):
      secondRideStartTime = max(landFinishTime, waterStartTime[j])
      result = min(result, secondRideStartTime + waterDuration[j])
  
  for i in range(len(waterStartTime)):
    waterFinishTime = waterStartTime[i] + waterDuration[i]
    for j in range(len(landStartTime)):
      secondRideStartTime = max(waterFinishTime, landStartTime[j])
      result = min(result, secondRideStartTime + landDuration[j])
  return result

if __name__ == '__main__':
  main()