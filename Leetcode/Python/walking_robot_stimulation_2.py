class Robot:
  def __init__(self, width: int, height: int):
    self.x = 0
    self.y = 0
    self.dir = "East"
    self.width = width
    self.height = height

  def step(self, num: int) -> None:
    perimeter = 2 * (self.width + self.height) - 4
    num = num % perimeter
    if num == 0:
      num = perimeter
    
    while num > 0:
      if self.dir == "East":
        step = min(self.x + num, self.width - 1)
        remaining_steps = num - (step - self.x)
        num = remaining_steps
        if remaining_steps == 0: 
          self.x = step
        else:
          self.x = step
          self.dir = "North"
      elif self.dir == "West":
        step = max(self.x - num, 0)
        remaining_steps = num - (self.x - step)
        num = remaining_steps
        if remaining_steps == 0: 
          self.x = step
        else:
          self.x = step
          self.dir = "South"
      elif self.dir == "North":
        step = min(self.y + num, self.height - 1)
        remaining_steps = num - (step - self.y)
        num = remaining_steps
        if remaining_steps == 0: 
          self.y = step
        else:
          self.y = step
          self.dir = "West"
      else:
        step = max(self.y - num, 0)
        remaining_steps = num - (self.y - step)
        num = remaining_steps
        if remaining_steps == 0: 
          self.y = step
        else:
          self.y = step
          self.dir = "East"

  def getPos(self) -> list[int]:
    return [self.x, self.y]

  def getDir(self) -> str:
    return self.dir