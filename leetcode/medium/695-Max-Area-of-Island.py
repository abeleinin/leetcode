#!/usr/bin/python3

class Solution:
  curr = 0                
  # Initial Solution
  def maxAreaOfIsland(self, grid) -> int:
    global curr
    res = 0
    for r in range(len(grid)):
      for c in range(len(grid[0])):
        if grid[r][c] == 1: 
          self.curr += 1
          self.mark(grid, r, c)
          res = max(res, self.curr)
          self.curr = 0
    return res                    
                    
  def mark(self, grid, r, c):
    global curr
    grid[r][c] = 2
        
    if r + 1 < len(grid) and grid[r + 1][c] == 1:
      self.curr += 1
      self.mark(grid, r + 1, c)
    if r - 1 >= 0 and grid[r - 1][c] == 1:
      self.curr += 1
      self.mark(grid, r - 1, c)
    if c + 1 < len(grid[0]) and grid[r][c + 1] == 1:
      self.curr += 1
      self.mark(grid, r, c + 1)
    if c - 1 >= 0 and grid[r][c - 1] == 1:
      self.curr += 1
      self.mark(grid, r, c - 1)
