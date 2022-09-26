#!/usr/bin/python3

class Solution:
  # Initial Solution
  def setZeros(self, matrix):
    """
    Do not return anything, modify matrix in-place instead.
    """
    copy = [row[:] for row in matrix]
    for r in range(len(matrix)):
      for c in range(len(matrix[0])):
        if copy[r][c] == 0:
          for i in range(len(matrix[0])):
            matrix[r][i] = 0
          for i in range(len(matrix)):
            matrix[i][c] = 0

  # Faster solution using less space
  def setZeroes(self, matrix):
    """
    Do not return anything, modify matrix in-place instead.
    """
    rows = [0] * len(matrix)
    cols = [0] * len(matrix[0])
    for r in range(len(matrix)):
      for c in range(len(matrix[0])):
        if matrix[r][c] == 0:
          rows[r] = 1
          cols[c] = 1

    for i, val in enumerate(rows):
      if val == 1:
        for j in range(len(matrix[0])):
          matrix[i][j] = 0

    for i, val in enumerate(cols):
      if val == 1:
        for j in range(len(matrix)):
          matrix[j][i] = 0
