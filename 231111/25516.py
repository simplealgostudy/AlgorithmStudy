import sys
from collections import defaultdict
from collections import deque
n, k = map(int , input().split())

lines = sys.stdin.readlines()

tree_dict = defaultdict(list)
arr = lines[-1].strip().split()
for i in range(0  , len(lines)-1):
    p , c = map(int , (lines[i].strip().split()))
    tree_dict[p].append(c)
    
def bfs(tree_dict , arr , k):
    start_node = 0
    count = 0
    apple = 0
    que = deque()
    que.append((start_node , count))
    while que:
        node , count = que.popleft()
        if count <= k:
            if arr[node] == '1':
                apple += 1
            for x in tree_dict[node]:
                que.append((x,count+1))
    return print(apple)
    
bfs(tree_dict , arr , k)