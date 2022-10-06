# Solution 1:
class Solution:
    def canJump(self, nums):
        index = 0
        count = nums[index]
        rest = len(nums) - 1 
        while True:
            curr = nums[index]
            if curr > count:
                count = curr
            if curr >= rest:
                return True
            if curr == 0 and count == 0:
                return False
            count -= 1
            rest -= 1
            index += 1
