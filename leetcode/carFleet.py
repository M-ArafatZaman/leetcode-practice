from typing import List

# https://leetcode.com/problems/car-fleet/
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        mp = list(map(list, zip(position, speed)))
        mp.sort()
        last_end_time = None
        fleet = 0
        while len(mp) > 0:
            curr = mp.pop()

            if not last_end_time:
                last_end_time = (target-curr[0])/curr[1]


            curr_end = (target-curr[0])/curr[1]

            if curr_end > last_end_time:
                fleet += 1
                last_end_time = curr_end
            
        return fleet + 1

if __name__ == "__main__":
    sol = Solution()
    print(sol.carFleet(12, [10,8,0,5,3], [2,4,1,1,3]))
    print(sol.carFleet(10, [3], [3]))
    print(sol.carFleet(100, [0,2,4], [4,2,1]))
    print(sol.carFleet(10, [6,8], [3,2])) # 2