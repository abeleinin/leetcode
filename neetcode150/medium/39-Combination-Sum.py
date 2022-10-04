# Solution 1
class Solution:
    def combinationSum(self, candidates, target):
        res = []
        curr = []

        def createSum(nums, target, index):
            if target == 0:
                res.append(curr.copy())
                return 
            for i in range(index, len(nums)):
                if target - nums[i] >= 0:
                    curr.append(nums[i])
                    createSum(nums, target - nums[i], i)
                    curr.pop()
        createSum(candidates, target, 0)
        return res    