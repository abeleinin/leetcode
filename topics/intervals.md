# Intervals

- [General Notes](#general-notes)
- [Merge Intervals](#merge-intervals)
- [Neetcode 150 Questions](#neetcode-150-questions)
- [Reference](#references)

## General Notes

### Sorting 

Often you'll need to sort the intervals by the start values:

```python
intervals = sorted(intervals, key=lambda x: x[0])
```

### Specific Cases when considering 2 intervals

Relationship between two intervals A and B must fall into 1 of 3 cases:

1. Interval A and B do not overlap: [[1, 3], [4, 5]]
2. Interval A and B partially overlap: [[1, 3], [2, 5]]
3. Interval A and B completely overlap: [[1, 5], [2, 4]]


## Merge Intervals

- Implementation in [Python](../neetcode150/medium/57-Merge-Intervals.py)

### Notes

- Sort by start index
- Use a stack containing the 0th interval
- Merge overlapped intervals and update top stack element
- Append non-overlapping intervals with curr top stack element


## Neetcode 150 Questions

- [Insert Interval](https://leetcode.com/problems/insert-interval/)
- [Merge Intervals](https://leetcode.com/problems/merge-intervals/)
- [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)
- Meeting Rooms (Premium)
- Meeting Rooms II (Premium)
- [Minimum Interval to Include Each Query](https://leetcode.com/problems/minimum-interval-to-include-each-query/)

## References 

[Leetcode is Easy! The Interval Pattern](https://medium.com/@timpark0807/leetcode-is-easy-the-interval-pattern-d68a7c1c841)