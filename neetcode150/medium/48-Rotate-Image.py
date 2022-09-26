#!/usr/bin/python3

# Solution 1
class Solution:
  # Matrix copy and Helper function:
  # A 90 degrees rotation is the same as converting all the 
  # columns to rows. If we get the values of the column we
  # can simply iterate through the column values assigning
  # the proper value to the correct index in the matrix.
  # The copy of the matrix is necessary because after we 
  # manipulate the values for the first row it will mess up 
  # future columns.
  def rotate(self, matrix):
    """
    Do not return anything, modify matrix in-place instead.
    """
    # Copy matrix
    copy = [row[:] for row in matrix]
    for r in range(len(matrix)):
      # Get the current column
      col = self.column(copy, r)
      for c in range(len(matrix)):
        # Assign the column value
        matrix[r][c] = col[c]

  # Get the current row in descending order
  def column(self, matrix, c):
    col = []
    for r in range(len(matrix)):
      # insert at the beginning of the list so that values
      # are in descending order.
      col.insert(0, matrix[r][c])
    return col 

# Solution 2
class Solution: 
  # Faster Matrix copy solution:
  def rotate(self, matrix):
    # copy the given matrix
    copy = [row[:] for row in matrix] 
    for r in range(len(matrix)):
      for c in range(len(matrix)):
        # Traverse the columns of the matrix from bottom to top 
        # and assign them to the values of the rows.
        matrix[r][c] = copy[len(matrix) - 1 - c][r]