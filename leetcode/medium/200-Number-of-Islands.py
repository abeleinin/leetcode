#!/usr/bin/python3

class Solution:
  # Initial DFS Solution 
  def numIslands(self, grid) -> int:
    if not grid:
      return 0
        
    rows, columns = len(grid), len(grid[0])
    visited = set()
    islands = 0
        
    def bfs(r, c):
        q = []
        visited.add((r, c))
        q.append((r, c))
        while q:
          r, c = q.pop()
          directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
          for dr, dc in directions:
            if ((r + dr) in range(rows) and 
              (c + dc) in range(columns) and
              grid[r + dr][c + dc] == "1" and
              (r + dr, c + dc) not in visited):
              q.append((r + dr, c + dc))
              visited.add((r + dr, c + dc))
        
    for r in range(rows):
      for c in range(columns):
        if grid[r][c] == "1" and (r, c) not in visited:
          bfs(r, c)
          islands += 1 

    return islands

    # Elegant Solution by renaming visited nodes
    def numIslands(self, grid: List[List[str]]) -> int:
        islands = 0
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == "1":
                    islands += 1 
                    self.mark(grid, r, c)
        return islands
    
    def mark(self, grid, o, i):
        grid[o][i] = "2"
        if o + 1 < len(grid) and grid[o + 1][i] == "1":
            self.mark(grid, o + 1, i)
        if o - 1 >= 0 and grid[o - 1][i] == "1":
            self.mark(grid, o - 1, i)
        if i + 1 < len(grid[0]) and grid[o][i + 1] == "1":
            self.mark(grid, o, i + 1)
        if i - 1 >= 0 and grid[o][i - 1] == "1":
            self.mark(grid, o, i - 1)