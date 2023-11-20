import sys


out = []

for i in sys.stdin.readlines():

    l = [int(_) for _ in i.split()]

    # Build prefix and suffix
    prefix = [0] * (len(l))
    for j in range(1, len(l)):
        prefix[j] = l[j-1] + prefix[j-1]

    suffix = [0] * (len(l))

    for j in range(len(l)-2, -1, -1):
        suffix[j] = l[j+1] + suffix[j+1]

    for k in range(len(l)):
        if suffix[k] + prefix[k] == l[k]:
            out.append(l[k])
            break


for i in out:
    print(i)
