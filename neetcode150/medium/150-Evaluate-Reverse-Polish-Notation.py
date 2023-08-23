class Solution:
    def evalRPN(self, tokens: list) -> int:
        stack = []
        for token in tokens:
            if token == "+":
                x = stack.pop()
                y = stack.pop()
                stack.append(x + y)
            elif token == "-":
                x = stack.pop()
                y = stack.pop()
                stack.append(y - x)
            elif token == "*":
                x = stack.pop()
                y = stack.pop()
                stack.append(x * y)
            elif token == "/":
                x = stack.pop()
                y = stack.pop()
                stack.append(int(y / x))
            else:
                stack.append(int(token))
        
        return stack[0]