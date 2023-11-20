from math import sqrt, pow


v = []
for i in range(3):

    v.append(tuple([int(i) for i in input().split()]))

dist = {}
for x0, y0 in v:
    for x1, y1 in v:
        d = sqrt( pow(x0-x1, 2) + pow(y0 - y1, 2) )
        
        if (x0, y0) not in dist:
            dist[(x0, y0)] = {}

        dist[(x0, y0)][(x1, y1)] = d

max = -10
max_v = []
for i in dist:
    for j in dist[i]:
        if dist[i][j] >= max:
            max = dist[i][j]
            max_v = [i, j]


x_mid = (max_v[0][0] + max_v[1][0])/2
y_mid = (max_v[0][1] + max_v[1][1])/2

v_3 = ()
for t in v:
    is_same = False
    for t1 in max_v:
        if t == t1:
            is_same = True
            break
    
    if not is_same:
        v_3 = t

d1 = sqrt( pow(x_mid-v_3[0], 2) + pow(y_mid - v_3[1], 2) )

doubled_vec = (2*(x_mid - v_3[0]), 2*(y_mid - v_3[1]))

final_vec = (v_3[0]+doubled_vec[0], v_3[1]+doubled_vec[1])

print(int(final_vec[0]), int(final_vec[1]))