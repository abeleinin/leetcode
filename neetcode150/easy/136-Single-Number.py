# Solution 1
class Solution:
    def singleNumber(self, nums):
        a = 0
        for n in nums:
            a ^= n
        return a