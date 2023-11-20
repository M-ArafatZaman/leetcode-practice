n = int(input())

rows = []
for i in range(n):
    j = input()    
    
    rows.append(j)

# bfs to bottom

visited = [[False, False, False] for i in range(len(rows))]
queue = [] # [(y, x)]
# Starting points
starting_row = rows[0]

for i in range(3):
    if starting_row[i] == ".":
        queue.append((0,i))

reached = False
while len(queue) > 0:
    y, x = queue.pop(0)
    visited[y][x] = True

    if y == n-1:
        reached = True
        break

    if y < (n-1) and rows[y][x] == rows[y+1][x] and rows[y][x] != "/" and not visited[y+1][x]:
        visited[y+1][x] = True
        queue.append((y+1,x))
    
    if x < 2 and rows[y][x] == rows[y][x+1] and rows[y][x] != "/" and not visited[y][x+1]:
        visited[y][x+1] = True
        queue.append((y, x+1))

    if x > 0 and rows[y][x] == rows[y][x-1] and rows[y][x] != "/" and not visited[y][x-1]:
        visited[y][x-1] = True
        queue.append((y, x-1))

    if y < (n-1) and rows[y][x] == "." and rows[y+1][x] == "/" and not visited[y+1][x]: 
        visited[y+1][x] = True
        queue.append((y+1, x))

    if y < (n-1) and rows[y][x] == "/" and rows[y+1][x] == "*" and not visited[y+1][x]:
        visited[y+1][x] = True
        queue.append((y+1, x))

    if y < (n-1) and rows[y][x] == "*" and rows[y+1][x] == "." and not visited[y+1][x]:
        visited[y+1][x] = True
        queue.append((y+1, x))

    
if reached:
    print("YES")
else:
    print("NO")