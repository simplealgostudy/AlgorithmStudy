def solution(prices)
    answer = []
    
    for i in 0...prices.length()
        cnt = 0
        for j in i...prices.length()
            if prices[j] < prices[i]
                cnt+=1
                break
            end
            cnt+=1
        end
        answer.push cnt-1
    end
    return answer
end