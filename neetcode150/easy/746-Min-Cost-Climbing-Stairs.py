# Solution 1
class Solution:
  def minCostClimbingStairs(self, cost):

    cost.append(0)

    for i in range(len(cost) - 3, -1, -1):
      cost[i] += min(cost[i+1], cost[i+2])

    return min(cost[0], cost[1])
  
# Solution 2
class Solution:
  def minCostClimbingStairs(self, cost):
    l = len(cost)
    for i in range(2,l):
      cost[i] += min(cost[i-1], cost[i-2])
    return min(cost[l-1], cost[l-2])