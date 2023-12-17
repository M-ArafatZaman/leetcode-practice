from collections import defaultdict
tests = int(input())

for _ in range(tests):
    n = int(input())
    nums = []
    highest = 0
    start = 0

    has_num = defaultdict(bool)
    for i in range(n):
        s = int(input())
        while has_num[s]:
            has_num[nums[start]] = False
            start += 1
        nums.append(s)
        has_num[s] = True
        highest = max(highest, len(nums)-start)
    print(highest)

    