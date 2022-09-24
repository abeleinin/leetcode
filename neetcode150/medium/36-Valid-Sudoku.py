#!/usr/bin/python3
from collections import defaultdict

class Solution:
  # Optimal solution O(n^2)
  def isValidSudoku(self, board) -> bool:
    row = defaultdict(set)
    col = defaultdict(set)
    grid = defaultdict(set)
    for r in range(9):
      for c in range(9):
        if board[r][c] == ".":
          continue
        if (board[r][c] in row[r] or 
          board[r][c] in col[c] or
          board[r][c] in grid[(r // 3, c // 3)]):
          return False
        row[r].add(board[r][c])
        col[c].add(board[r][c])
        grid[(r // 3, c // 3)].add(board[r][c])
    return True