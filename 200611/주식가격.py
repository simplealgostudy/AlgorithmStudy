def solution(prices):
    answer = []
    for i in range(len(prices) - 1):
        cnt = 0
        for j in range(i, len(prices)):
            if prices[j] < prices[i]:
                cnt+=1
                break
            cnt+=1
        answer.append(cnt-1)
    answer.append(0)
    
    return answer