from typing import List

class Solution:
  # Intital solution O(k log n)
  def topKFrequent(self, nums: List[int], k: int) -> List[int]:
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
  def topKFrequent(self, nums: List[int], k: int) -> List[int]:
      h = {}
      freq = [[] for i in range(len(nums) + 1)]

      for n in nums:
          h[n] = h.get(n, 0) + 1
        
      for n, c in h.items():
          freq[c].append(n)

      res = []
      for i in range(len(freq) - 1, 0, -1):
          bucket = freq[i]
          while bucket:
              res.append(bucket.pop())
              k -= 1
              if k == 0:
                  return res