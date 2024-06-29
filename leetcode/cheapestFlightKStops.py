from typing import List
import heapq

# https://leetcode.com/problems/cheapest-flights-within-k-stops/
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        adj = {i: {} for i in range(n)}
        cheapest = 1e5
        found = False
        flight_visited = {i: {} for i in range(n)}
        flight_visited[None] = {}

        # Form adj map
        for _from, _to, _price in flights:
            adj[_from][_to] = _price
            flight_visited[_from][_to] = set()

        # Use a variant of djikstras
        pq = []
        # (running total, from, to, running steps)
        pq.append((0, None, src, 0))

        flight_visited[None][src] = set([0])

        while len(pq) > 0:
            curr_cost, prev, curr, steps = heapq.heappop(pq)

            if steps in flight_visited[prev][curr]:
                continue

            if curr == dst:
                cheapest = min(cheapest, curr_cost)
                found = True

            if steps > k:
                continue
            
            # flight_visited[prev][curr] = True
            flight_visited[prev][curr].add(steps)

            for to_city in adj[curr]:
                heapq.heappush(pq, (curr_cost + adj[curr][to_city], curr, to_city, steps+1))

        return cheapest if found else -1


if __name__ == "__main__":
    runner = Solution()
    print(runner.findCheapestPrice(4, [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], 0, 3, 1))
    print(runner.findCheapestPrice(3, [[0,1,100],[1,2,100],[0,2,500]], 0, 2, 1))
    print(runner.findCheapestPrice(3, [[0,1,100],[1,2,100],[0,2,500]], 0, 2, 0))
    print(runner.findCheapestPrice(5, [[0,1,5],[1,2,5],[0,3,2],[3,1,2],[1,4,1],[4,2,1]], 0, 2, 2)) # 7