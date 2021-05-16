def solution(lottos, win_nums):
    answer = []
    minRate = 7
    maxRate = 7

    for i in range(len(lottos)):
        if lottos[i] in win_nums:
            maxRate-=1
            minRate-=1
    maxRate-= lottos.count(0)
    if maxRate<1:
        maxRate = 1
    elif maxRate>6:
        maxRate = 6
    if minRate<1:
        minRate = 1
    elif minRate>6:
        minRate = 6
    answer.append(maxRate)
    answer.append(minRate)
    return answer

if __name__=="__main__":
    lottos = [44, 1, 0, 0, 31, 25]
    win_nums = 	[31, 10, 45, 1, 6, 19]
    print(solution(lottos, win_nums))
