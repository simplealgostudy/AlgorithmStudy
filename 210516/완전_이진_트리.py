k = 0 # 층 수
count = 0
answer = []
order = []

def find(index, depth):
    global count
    if k == depth: # 마지막 층이면
        answer[index] = order[count]
        count += 1
    else: # 마지막 층이 아니면
        find(index*2, depth + 1) # 왼쪽 자식 노드 검사
        answer[index] = order[count] # 현재 노드값 검사
        count += 1
        find(index*2+1, depth + 1) # 오른쪽 자식 노드 검사

if __name__=="__main__":
    k = int(input()) # 층 수 입력받음
    number = 2**k-1 # 전체 노드 갯수
    answer = [0]*(number+1) # 전체 노드 갯수만큼 리스틑 늘려 줌
    # +1 해 준 이유는 노드의 인덱스를 1부터로 고려했기 때문.
    order = [int(x) for x in input().strip().split()] # 지도에 적힌 순서 입력받음
    find(1, 1)
    del answer[0] 
    # del 해 주지 않으면 [0, 3, 6, 2, 1, 4, 5, 7] 이렇게 첫 번째에 무의미한 0이 들어감.

    idx = 0
    for i in range(0, k): # 층 수 만큼 줄 바꿈
        for j in range(2**i): # 층마다 출력하는 노드의 갯수는 2^n(단, n은 0부터)
            print(answer[idx], end=' ')
            idx+=1
        print()
