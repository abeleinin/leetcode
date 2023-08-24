class Solution:
    def generateParenthesis(self, n: int) -> list:
        res = []
        def gen(o, c, temp):
            if o == n and c == n:
                res.append(temp)
                return
            if o < n:
                gen(o + 1, c, temp + "(")
            if c < o:
                gen(o, c + 1, temp + ")")
        
        gen(0, 0, "")
        return res