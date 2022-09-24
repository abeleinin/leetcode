#!/usr/bin/python3
class Solution:
  # Intital solution O(k log n)
  def topKFrequent(self, nums: list, k: int) -> list:
    d = {} 
    for n in nums:
      if n in d:
        d[n] += 1
      else:
        d[n] = 1
        
    s = []
    m = int()
    i = int()
    for v in range(k):
      m = int()
      for e in d:
        if d[e] > m:
          m = max(m, d[e])
          i = e
      del d[i]
      s.append(i) 
    return s

  # Optimal solution O(n) using bucket sort
  def topKFrequent(self, nums: list, k: int) -> list:
    count = {}
    freq = [[] for i in range(len(nums) + 1)]
        
    for n in nums:
      count[n] = 1 + count.get(n, 0)
    for n, c in count.items():
      freq[c].append(n)
        
    res = []
    for l in range(len(nums), 0, -1):
      for i in freq[l]:
        res.append(i)
        if len(res) == k:
          return res