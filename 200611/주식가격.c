#include <stdio.h>

int* solution(int prices[], size_t prices_len) {
    int* answer = (int*)malloc(prices_len * sizeof(int));
    
    for (int i = 0; i < prices_len; i++) 
    {
        *(answer+i) = 0;
        for (int j = i + 1; j < prices_len; j++)
        {
            if (prices[j] >= prices[i])
            {
                *(answer+i) += 1;
            }
            else
            {
                *(answer+i) += 1;
                break;
            }
        }
    }
    
    return answer;
}