#!/usr/bin/python3
class Solution:
  # Initial Solution
  def groupAnagrams(self, strs: list) -> list:
    g = []
    for w in strs:
      s = sorted(w)
      s = ''.join(s)
      g.append(s)
    
    h = {}
    for i, w in enumerate(g):
      if w in h:
        h[w].append(strs[i])
      else:
        h[w] = [strs[i]]
    
    sol = []
    for s in set(g):
      sol.append(h[s])

    return sol
  
  # Cleaner solution
  def groupAnagrams(self, strs: list) -> list:
    d = {}
    for w in strs:
      s = ''.join(sorted(w))
      if s not in d:
        d[s] = [w]
      else:
        d[s] += [w]
    # Two ways to return a dictionaries values
    # return [d[i] for i in d]
    return d.values()

