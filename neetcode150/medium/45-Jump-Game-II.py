# Solution 1
class Solution:
    def jump(self, nums):
        jumps = 0
        currEnd = 0
        currFar = 0
        for i in range(len(nums) - 1):
            currFar = max(currFar, i + nums[i])
            if i == currEnd:
                jumps += 1
                currEnd = currFar
        return jumps