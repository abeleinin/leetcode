# Solution 1
class Solution:
  def search(self, nums, target):
    return self.binary(nums, 0, len(nums) - 1, target)
    
  def binary(self, nums, begin, end, key):
    if begin > end:
      return -1
        
    mid = (end + begin) // 2
        
    if nums[mid] == key:
      return mid
        
    elif nums[begin] < nums[mid] and key <= nums[mid] and key >= nums[begin]:
      return self.binary(nums, begin, mid - 1, key)
    elif nums[mid] < nums[end] and key >= nums[mid] and key <= nums[end]:
      return self.binary(nums, mid + 1, end, key)
    elif nums[end] < nums[mid]:
      return self.binary(nums, mid + 1, end, key)
    elif nums[begin] > nums[mid]:
      return self.binary(nums, begin, mid - 1, key)
    return -1
           