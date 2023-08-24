class Solution:
    def insert(self, intervals: list, newInterval: list) -> list:
        res = []
        for i in range(len(intervals)):
            if newInterval[1] < intervals[i][0]:
                res.append(newInterval)
                return res + intervals[i:]
            elif newInterval[0] <= intervals[i][1]:
                start = min(intervals[i][0], newInterval[0])
                end = max(intervals[i][1], newInterval[1])
                newInterval = [start, end]
            else:
                res.append(intervals[i])

        res.append(newInterval)
        return res
        
