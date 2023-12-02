s = input()

if not s.endswith("O") or "OO" in s:
    print("INVALID")
    exit(0)

def CST(n, length):
    res = ""
    if length == 0:
        return ""
    
    if n % 2 == 0:
        return "E" + CST(n/2, length-1)
    else:
        return "O" + CST(3*n + 1, length-1)

def getCST(parity, n):
    if parity == "O" and n == 0:
        return 3
    if parity == "O":
        curr = n - 1
        last = curr
        while curr > 0:
            if (3 * curr + 1) > n:
                last = curr
            curr -= 2
        return last
    elif parity == "E":
        return 2 * n

n = 0
for i in range(len(s)-1, -1, -1):
    n = getCST(s[i], n)

print(n)