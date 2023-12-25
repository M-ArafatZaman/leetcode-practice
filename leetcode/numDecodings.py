d = {}

# https://leetcode.com/problems/decode-ways/
class Solution:
    def numDecodings(self, s: str) -> int:
        if s in d:
            return d[s]

        if s[0] == "0": return 0
        
        if len(s) == 1:
            return 1
        
        if len(s) == 2 and 1 <= int(s) <= 26:
            return 1 + self.numDecodings(s[1:])

        if s == "":
            return 0

        count = 0

        if 1 <= int(s[0]) <= 9:
            count += self.numDecodings(s[1:])
        
        if 1 <= int(s[0:2]) <= 26:
            count += self.numDecodings(s[2:])

        d[s] = count

        return count

if __name__ == "__main__":
    sol = Solution()
    print(sol.numDecodings("12"))