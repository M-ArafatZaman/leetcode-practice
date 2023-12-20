# https://leetcode.com/problems/buy-two-chocolates/description/
class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        prices.sort()
        l = prices[0] + prices[1]
        return (money-l) if l <= money else money
    
