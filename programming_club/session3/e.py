rhyme = len(input().split(" ")) - 1
n = int(input())
students = []
for s in range(n):
    students.append(input())

team1 = []
team2 = []

t = True
i = 0
while len(students) > 0:
    i = (i+rhyme) % len(students)
    if t: team1.append(students.pop(i))
    else: team2.append(students.pop(i))
    t = not t

print(len(team1))
for s in team1:
    print(s)
print(len(team2))
for s in team2:
    print(s)
