from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stk = []
        s = 0
        for i in tokens:
            if i not in "+-*/":
                stk.append(int(i))
            else:
                b, a = stk.pop(), stk.pop()
                if i == "+": s = a + b
                if i == "-": s = a - b
                if i == "*": s = a * b
                if i == "/": s = int(a / b)
                stk.append(s)

        return stk[0]

if __name__ == "__main__":
    sol = Solution()
    print(sol.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]))