#!/usr/bin/python3
class Solution:
    def merge(self, intervals: list) -> list:

        intervals = sorted(intervals, key=lambda x: x[0]) 

        stack = [intervals[0]]

        for inter in intervals[1:]:
            if stack[-1][1] >= inter[0]:
                stack[-1][1] = max(stack[-1][1], inter[1])
            else:
                stack.append(inter)

        return stack