#!/usr/bin/python3

class Solution:
  # Initial solution with helper function and hashmap O(n)
  def climbStairs(self, n: int) -> int:
    val = {}
    def helper(n: int) -> int:
      if n in val: return val[n]

      if n == 1: return 1
      if n == 2: return 2

      result = helper(n - 2) + helper(n - 1) 
      val[n] = result
      return result
    return helper(n)

  v = {}
  # Solution without helper function
  def climbStairs(self, n: int) -> int:
    global v
    if n in self.v:
      return self.v[n]
    if n <= 1:
      return 1
    a = self.climbStairs(n - 1)
    b = self.climbStairs(n - 2)
    self.v[n] = a + b
    return a + b
    
  # Time: O(n) Space: O(1)
  def climbStairs(self, n: int) -> int:
    curr = 1
    prev = 0

    while n > 0:
      temp = curr
      curr += prev
      prev = temp
      n -= 1
            
    return curr  

    # Solution using memoization
    def climbStairs(self, n: int) -> int:
        m = {}
        m[1] = 1
        m[2] = 2
        
        def dp(n):
            if n in m:
                return m[n]
            else:
                m[n] = dp(n - 1) + dp(n - 2)
                return m[n]
        return dp(n)