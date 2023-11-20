from collections import defaultdict

i = input().split()
n = int(i[0])
original = i[1]
guess = i[2]

is_visited = [False] * n

r = 0

chars = defaultdict(int)

for k in range(n):
    if original[k] == guess[k]:
        is_visited[k] = True
        r += 1
    else:
        chars[original[k]] += 1

s = 0
for k in range(n):
    if chars[guess[k]] > 0 and not is_visited[k]:
        s += 1
        chars[guess[k]] -= 1

print(r, s)
    