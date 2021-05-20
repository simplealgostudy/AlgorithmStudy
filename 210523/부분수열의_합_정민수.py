# https://www.acmicpc.net/problem/1182
result = 0
N = 0
li = []

def sumOfSubset(idx, sum):
    global result
    
    if idx>=N:
        return

    sum += li[idx]

    if sum == S:
        result += 1
    
    sumOfSubset(idx+1, sum-li[idx])
    sumOfSubset(idx+1, sum)

if __name__=="__main__":
    N, S = map(int, input().split())
    li = [int(x) for x in input().strip().split()]
    sumOfSubset(0, 0)
    print(result)
