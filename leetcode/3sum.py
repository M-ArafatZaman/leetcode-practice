
# https://leetcode.com/problems/3sum/description/
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        triplets = defaultdict(bool)
        ans = []
        nums.sort()
        for i in range(len(nums)):
            # 2 sum
            if nums[i] > 0: break
            
            target = -nums[i]
            a, b = 0, len(nums)-1
            while a < b:
                if a == i:
                    a += 1
                    continue
                if b == i:
                    b -= 1
                    continue
                
                if nums[a] + nums[b] < target:
                    a += 1
                elif nums[a] + nums[b] > target:
                    b -= 1
                    
                if nums[a] + nums[b] == target and a != b and a != i and b != i:
                    d = [nums[i], nums[a], nums[b]]
                    d.sort()
                    if not triplets[str(d)]:
                        ans.append(d)
                        triplets[str(d)] = True
                        # [3,0,-2,-1,1,2]
                    b -= 1

        return ans