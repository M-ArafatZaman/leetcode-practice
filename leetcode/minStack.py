import heapq

# https://leetcode.com/problems/min-stack/
class MinStack:

    def __init__(self):
        self.stk = []
        self.curr_min = 2**33

    def push(self, val: int) -> None:
        self.stk.append(val)
        self.curr_min = min(self.curr_min, val)

    def pop(self) -> None:
        rem = self.stk.pop()
        if rem == self.curr_min:
            self.curr_min = min(self.stk) if len(self.stk) > 0 else 2**33

    def top(self) -> int:
        return self.stk[-1]

    def getMin(self) -> int:
        return self.curr_min


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()