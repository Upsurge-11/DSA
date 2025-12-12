def main():
  numberOfUsers = int(input())
  events = [list(map(int, input().split())) for _ in range(numberOfUsers)]
  print(countMentions(numberOfUsers, events))

def countMentions(numberOfUsers: int, events: list[list[int]]) -> list[int]:
  mentions = [0] * numberOfUsers
  backOnlineAt = [0] * numberOfUsers
  events.sort(key=lambda e: (int(e[1]), e[0] == "MESSAGE"))
  
  for type, time, data in events:
    time = int(time)
    if type == "OFFLINE":
      backOnlineAt[int(data)] = time + 60
      continue
    
    for message in data.split():
      if message == "ALL":
        for i in range(numberOfUsers):
          mentions[i] += 1
      elif message == "HERE":
        for i in range(numberOfUsers):
          if time >= backOnlineAt[i]:
            mentions[i] += 1
      else:
        mentions[int(message[2:])] += 1

  return mentions

if __name__ == '__main__':
  main()