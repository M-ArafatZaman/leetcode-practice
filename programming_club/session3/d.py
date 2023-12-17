lect = int(input())
coff = list(map(int, list(input())))

coff_count = 0
attends = 0
for i in coff:
    if i == 1:
        attends += 1
        coff_count = 2
    elif coff_count > 0:
        attends += 1
        coff_count -= 1

print(attends)
