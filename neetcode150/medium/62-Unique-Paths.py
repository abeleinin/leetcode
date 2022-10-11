import collections
# Solution 1
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        d = collections.defaultdict(tuple)
        def dp(r, c):
            if r == 1 or c == 1:
                return 1 
            if (r, c) in d:
                return d[r, c]
            d[(r, c)] = dp(r, c - 1) + dp(r - 1, c)
            return d[(r, c)]
        
        return dp(m, n)

# Solution 2
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[1] * n] * m
        for r in range(1, m):
            for c in range(1, n):
                dp[r][c] = dp[r - 1][c] + dp[r][c - 1]
                
        return dp[m - 1][n - 1]
            