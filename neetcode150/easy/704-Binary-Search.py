#!/usr/bin/python3
from math import floor

class Solution:
    # Initial Solution
    def search(self, nums: list, target: int) -> int:
        begin = 0
        end = len(nums) - 1
        mid = floor(len(nums) / 2)
        
        while(begin <= end):
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                begin = mid + 1
                mid = floor((end + begin) / 2)
            elif nums[mid] > target:
                end = mid - 1
                mid = floor((end + begin) / 2)
        return -1

    # Recursive helper function solution
    def binary(self, left: int, right: int, nums: list, target: int):
      mid = floor((left + right) / 2)
      if left > right:
          return -1
      while(left <= right):
          if nums[mid] == target:
              return mid
          elif nums[mid] < target:
              return self.binary(mid + 1, right, nums, target)
          elif nums[mid] > target:
              return self.binary(left, mid - 1, nums, target)
    def search(self, nums: list, target: int) -> int:
        return self.binary(0, len(nums) - 1, nums, target)

    # More refined solution
    def search(self, nums: list, target: int) -> int:

        # left and right indices
        l = 0
        r = len(nums) - 1
        
        while l <= r:
            # use floor division to find middle index
            mid = (l + r) // 2
            # find value
            if nums[mid] == target:
                return mid
            # shift right index up 
            elif nums[mid] > target:
                r = mid - 1
            # shift left index up
            else:
                l = mid + 1
        return -1
        
