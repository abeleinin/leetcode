class Solution:
    def dailyTemperatures(self, temperatures: list) -> list:

        n = len(temperatures)
        res = [0] * n
        stack = [0]

        for i in range(1, n):
            while len(stack) > 0 and temperatures[i] > temperatures[stack[-1]]:
                index = stack.pop()
                res[index] = i - index
            stack.append(i)

        return res