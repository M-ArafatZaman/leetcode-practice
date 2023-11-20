import sys

matrices = []
tmp = []
j = 0 
for i in sys.stdin.readlines():
    if j % 2 == 0:
        matrices.append(tmp)
        tmp = []

    if i == "" or i == "\n": continue

    a, b = [int(_) for _ in i.split()]
    tmp.append([a, b])

    j += 1

m = []

for i in matrices:
    if len(i) == 0:
        continue
    m.append(i)

for i in range(len(m)):
    a, b = m[i][0]
    c, d = m[i][1]

    det = 1 / ((a * d) - (b * c))
    e = int(det * d)
    f = int(det * -b)
    g = int(det * -c)
    h = int(det * a)

    print(f"Case {i+1}:")
    print(e, f)
    print(g, h)
