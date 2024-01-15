# https://leetcode.com/problems/find-players-with-zero-or-one-losses/

class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        losses = {}
        
        for m in matches:
            if m[0] not in losses: losses[m[0]] = 0
            if m[1] not in losses: losses[m[1]] = 0
            losses[m[1]] += 1
            
        no_loss = []
        one_loss = []
        for i in losses:
            if losses[i] == 0:
                heapq.heappush(no_loss, i)
            elif losses[i] == 1:
                heapq.heappush(one_loss, i)
                
        answer = [[], []]

        while len(no_loss) > 0:
            answer[0].append(heapq.heappop(no_loss))
            
        while len(one_loss) > 0:
            answer[1].append(heapq.heappop(one_loss))
            
        return answer
        
        