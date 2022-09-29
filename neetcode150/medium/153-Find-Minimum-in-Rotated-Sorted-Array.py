# Solution 1
class Solution:
  def findMin(self, nums):
    begin = 0
    end = len(nums) - 1
    res = 100
        
    while begin <= end:
      mid = (begin + end) // 2
            
      if nums[mid] <= nums[begin] and nums[mid] <= nums[end]:
        res = min(res, nums[mid])
            
      if nums[begin] >= nums[mid] and nums[end] <= nums[mid]:
        begin = mid + 1
      elif nums[end] <= nums[mid]: 
        begin = mid + 1
      elif nums[begin] < nums[mid]:
        end = mid - 1
      elif nums[end] > nums[mid]:
        end = mid - 1
    return res

# Solution 2
class Solution:
  def findMin(self, nums):
    l = 0
    r = len(nums) - 1
    while l < r:
      mid = (l + r) // 2

      if nums[mid] > nums[r]:
        l = mid + 1
      else:
        r = mid
    return nums[l]