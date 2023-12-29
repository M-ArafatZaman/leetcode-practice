from typing import List, Set

# https://leetcode.com/problems/generate-parentheses/
class Solution:
    
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 1: return ["()"]
        
        q = []
        q.append(("", ["(" for _ in range(n)], []))

        results = []

        while len(q) > 0:
            curr, openStk, closeStk = q.pop()

            if len(openStk) > 0: 
                q.append((curr+"(", openStk[:-1], closeStk[:] + [")"]))

            if len(closeStk) > 0:
                q.append((curr+")", openStk[:], closeStk[:-1]))

            if len(openStk) == 0 and len(closeStk) == 0:
                results.append(curr)

        return results


if __name__ == "__main__":
    sol = Solution()
    print(sol.generateParenthesis(1))
    print(sol.generateParenthesis(2))
    print(sol.generateParenthesis(3))
    print(sol.generateParenthesis(4))
    print(sol.generateParenthesis(5))


