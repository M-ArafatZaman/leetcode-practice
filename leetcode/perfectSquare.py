from collections import deque

# https://leetcode.com/problems/perfect-squares/
class Solution:
    def numSquares(self, n: int) -> int:
        # Generate squares till n
        squares = []
        curr = 1
        while curr ** 2 <= n:
            squares.append(curr ** 2)
            curr += 1

        # bfs (n, steps)
        queue = deque()
        queue.append((n, 0))
        visited = set()

        while len(queue) > 0:
            i, steps = queue.popleft()
            if (i, steps) in visited:
                continue
            visited.add((i, steps))

            if i == 0:
                return steps
            
            for sq in squares:
                if sq <= i:
                    queue.append((i-sq, steps + 1))
                else:
                    break
            
    
        return n

          

if __name__ == "__main__":
    runner = Solution()
    #print(runner.numSquares(12))
    assert runner.numSquares(12) == 3, "Wrong answer for n = 12"
    assert runner.numSquares(13) == 2, "Wrong answer for n = 13"
  