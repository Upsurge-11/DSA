def main():
  commands = list(map(int, input().split()))
  obstacles = [list(map(int, input().split())) for _ in range(int(input()))]
  print(robotSim(commands, obstacles))

def robotSim(commands: list[int], obstacles: list[list[int]]) -> int:
  x, y, direction = 0, 0, 0
  max_distance = 0
  obstacle_set = set(map(tuple, obstacles))

  for command in commands:
    if command == -2:
      direction = (direction - 1) % 4
    elif command == -1:
      direction = (direction + 1) % 4
    else:  # Move forward
      for _ in range(command):
        next_x, next_y = x, y
        if direction == 0:
          next_y += 1
        elif direction == 1:
          next_x += 1
        elif direction == 2:
          next_y -= 1
        elif direction == 3:
          next_x -= 1
        if (next_x, next_y) not in obstacle_set:
          x, y = next_x, next_y
          max_distance = max(max_distance, x**2 + y**2)
        else:
          break
  return max_distance

if __name__ == '__main__':
  main()