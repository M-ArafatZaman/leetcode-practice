import heapq

n, k = [int(i) for i in input().split()]

heap = [0] * k

for b in [int(i) for i in input().split()]:
    minimum = heapq.heappop(heap)
    minimum += b
    heapq.heappush(heap, minimum)

l = 0

print(heap)

for i in range(k):
    l = heapq.heappop(heap)

print(l)