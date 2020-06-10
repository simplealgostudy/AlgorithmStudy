#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    int survive;
    for (int i = 0; i < prices.size()-2; i++)
    {
        survive = 1;
        for (int j = i+1; j < prices.size()-1; j++)
        {
            if (prices[i] <= prices[j]) survive++;
            else break;
        }
        answer.push_back(survive);
    }
    answer.push_back(1);
    answer.push_back(0);
    return answer;
}
