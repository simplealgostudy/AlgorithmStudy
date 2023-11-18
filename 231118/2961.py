from itertools import combinations, permutations

n = int(input())
arr = []
gap = float("inf")
onetime = 0
nums =[]
for i in range(1,n+1):
    a,b = map(int , input().split())
    arr.append((a,b))
    nums.append(i)

combi = []
for i in range(1,n+1):
    combi += list(combinations(nums , i))
target = 0
for x in combi:
    new_arr = []
    for i in x:
        new_arr.append(i)
    s = 1
    b = 0
    for j in new_arr:
        s *= arr[j-1][0]
        b += arr[j-1][1]
    if gap > abs(s-b):
        gap = abs(s-b)
print(gap)
