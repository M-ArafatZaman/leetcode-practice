from typing import List 

# https://leetcode.com/problems/daily-temperatures/
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0] * len(temperatures)

        resStk = []
        # index, inc
        resStk.append((len(temperatures)-1, 0))

        while len(resStk) > 0:
            ind, inc = resStk.pop()
            res[ind] = inc
            nextInd = ind - 1
            
            if nextInd >= 0:
                if temperatures[nextInd] >= temperatures[ind]:
                    
                    while nextInd + inc < len(temperatures) \
                        and temperatures[nextInd] >= temperatures[nextInd+inc] \
                        and res[nextInd + inc] != 0:
                        
                        inc += 1
                    
                    resStk.append((nextInd, inc if nextInd + inc < len(temperatures) and temperatures[nextInd] < temperatures[nextInd+inc] else 0))
                else:
                    resStk.append((nextInd, 1))
        
        return res


if __name__ == "__main__":
    sol = Solution()
    print(sol.dailyTemperatures([73,74,75,71,69,72,76,73]))
    print(sol.dailyTemperatures([30,40,50,60]))
    print(sol.dailyTemperatures([30,60,90]))
    