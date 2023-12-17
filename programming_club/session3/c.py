
n = int(input())

s_n = 1
while n != 0:
    s = [""] * n
    l, r = 0, n-1
    while l <= r:
        s[l] = input()
        if l != r:
            s[r] = input()
        l += 1
        r -= 1
    
    print(f"SET {s_n}")
    for i in s:
        print(i)

    s_n += 1
    n = int(input())