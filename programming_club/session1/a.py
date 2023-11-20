# https://open.kattis.com/contests/ejgzay

n = int(input())
out = []

for _ in range(n):
    l = [int(i) for i in input().split()]

    curr = 2
    prev = l[1]

    while curr < (len(l)-1):
        if l[curr] != (prev+1):
            out.append(curr)
        else:
            prev = l[curr]
        curr += 1

for i in out:
    print(i)