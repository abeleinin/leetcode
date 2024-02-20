class Solution:
  def carFleet(self, target: int, position: list, speed: list) -> int:
    cars = []
    for i in range(len(position)):
      cars.append((position[i], (target - position[i]) / speed[i]))
    cars = sorted(cars, key = lambda x: x[0])

    stack = []

    for car in cars[::-1]:
      if len(stack) == 0:
        stack.append(car)
      elif car[1] > stack[-1][1]:
        stack.append(car)

    return len(stack)
