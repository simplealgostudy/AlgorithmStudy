

# 입력
# 2 3 4 --> Blue는 2초씩 걸림, Red는 4초씩 걸림, 손님 수 4
# 1 B 3 --> 1초 시각에 3개를 주문함, Blue
# 4 R 2 --> 4초 시각에 2개를 주문함, red
# 6 B 2 --> 6초 시각에 2개를 주문함, Blue
# 12 R 1 --> 12초 시각에 1개를 주문함, Red
# =======================================================
# 그렇다면
# ---------------------
# B = [1, 3, 5]
# R = [4, 7]
# ---------------------
# 그리고
# ---------------------
# B = [1, 3, 5, 7, 9]
# R = [4, 7, 12]
# ---------------------
# 여기서 포인트, 
# B에 들어올 때 6이 아닌 7에 들어왔다.
# R에 들어올 때 10이 아닌 12에 들어왔다.
# ---------------------
# 이제 각 값들에 순번을 매겨주자
# B = [1번, 2번, 4번, 5번, 7번]
# R = [3번, 6번, 8번]
# 여기서 포인트,
# 아까 위에서 B와 R에 같은 값 7이 들어있었다.
# B가 먼저다. 더 빠른 순번을 받는다.
# =======================================================
# 출력
# 5
# 1 2 4 5 7
# 3
# 3 6 8

from collections import deque

blueSpeed = 0
redSpeed = 0
guestNumber = 0 # 손님 수

blueTime = 0 # 상민, 포장이 끝날 때 까지 걸리는 시간
redTime = 0 # 지수, 포장이 끝날 때 까지 걸리는 시간

time = 0 # 손님이 주문한 시각
color = ''
giftAmount = 0 # 선물의 개수

blueQueue = deque([])
redQueue = deque([])



if __name__=="__main__":
    blueSpeed, redSpeed, guestNumber = map(int, input().split())

    # 주문 및 포장단계
    while guestNumber != 0:
        time, color, giftAmount = input().split()

        time = int(time)    # 입력받은거 그냥 형변환 해 준 거
        giftAmount = int(giftAmount)

        if color == 'B':
            if time<blueTime: # 손님이 주문한 시각이 포장하는중인 시각보다 작으면, 아직 포장중인 때에 손님을 받은경우임. 
                time = blueTime # 포장이 끝나는 시간으로 변경한다.
            for _ in range(giftAmount): # 주문한 선물의 개수
                blueQueue.append(time) # 시작 시간부터 넣는다.
                time +=blueSpeed # 포장 시간 간격으로 증가
                blueTime = time # 마지막 포장이 끝나는 시간
        else: # color == 'R'
            if time<redTime: # 손님이 주문한 시각이 포장하는중인 시각보다 작으면, 아직 포장중인 때에 손님을 받은경우임. 
                time = redTime # 포장이 끝나는 시간으로 변경한다.
            for _ in range(giftAmount): # 주문한 선물의 개수
                redQueue.append(time) # 포장 시간 간격으로 증가
                time += redSpeed
                redTime = time # 마지막 포장이 끝나는 시간
        guestNumber-=1
    # 주문 및 포장 단계 끝

    # 포장한 선물들에다가 번호 부여
    currentTime = 0 # 시간
    giftIndex = 1 # 선물의 번호

    blueAnswer = deque([])
    redAnswer = deque([])

    while len(blueQueue)!=0 or len(redQueue)!= 0:
        if len(blueQueue)!= 0 and currentTime == blueQueue[0]: # 현재 시간에 B 포장을 했으면
            blueAnswer.append(giftIndex)
            giftIndex+=1
            blueQueue.popleft()
            if len(blueQueue)!= 0 and currentTime == blueQueue[0]: 
                continue
        if len(redQueue)!=0 and currentTime == redQueue[0]: # 현재 시간에 R 포장을 했으면
            redAnswer.append(giftIndex)
            giftIndex+=1
            redQueue.popleft()
            if len(redQueue)!=0 and currentTime == redQueue[0]:
                continue
        currentTime+=1

# 출력
    print(len(blueAnswer))
    for b in blueAnswer:
        print(b, end=' ')
    print()
    print(len(redAnswer))
    for r in redAnswer:
        print(r, end=' ')
