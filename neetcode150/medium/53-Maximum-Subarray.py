# Solution 1:
class Solution:
    def maxSubArray(self, nums):
        tot = 0 
        best = nums[0] 
        for i in nums:
            if i > tot and tot < 0:
                tot = 0
            tot += i
            best = max(best, tot)
        return best
        