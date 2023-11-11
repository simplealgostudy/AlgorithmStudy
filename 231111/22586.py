import sys
from sys import stdin
sys.setrecursionlimit(10**8)
input = stdin.readline

class Node:
    def __init__(self, data, left_node, right_node):
        self.data = data
        self.left_node = left_node
        self.right_node = right_node

def in_order(node):
    if node.left_node != '-1':
        in_order(tree[node.left_node])
    a_list.append(node.data)
    if node.right_node != '-1':
        in_order(tree[node.right_node])

def similar_in_order(node):
    global cnt

    if node.left_node != '-1':
        similar_in_order(tree[node.left_node])
        cnt += 1

    if node.data == a_list[-1]: # 중위순회의 마지막 값과 같다면 종료
        print(cnt)
        exit(0)
    cnt += 1

    if node.right_node != '-1':
        similar_in_order(tree[node.right_node])
        cnt += 1


n = int(input())
tree = {}
for i in range(n):
    data, left_node, right_node = input().split()
    tree[data] = Node(data, left_node, right_node)

a_list = []
cnt = 0
in_order(tree['1'])
similar_in_order(tree['1'])