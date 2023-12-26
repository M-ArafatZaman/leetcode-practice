
# https://leetcode.com/problems/valid-parentheses/
class Solution:
    def isValid(self, s: str) -> bool:
        bracket = {")": "(", "]":"[", "}":"{"}
        stk = []
        for i in s:
            if i in "([{":
                stk.append(i)
            elif i in ")]}":
                if len(stk) == 0: return False
                if bracket[i] != stk.pop():
                    return False
        return True if len(stk) == 0 else False