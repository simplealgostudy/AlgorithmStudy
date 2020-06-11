#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
 
    for (int i = 0; i < prices.size()-1; i++) {
        for (int j = i+1; j < prices.size(); j++) {
            if (prices[i] > prices[j]) {
                answer.push_back(j - i);
                break;
            }
            else if (j == prices.size()-1) {
                answer.push_back(prices.size() - i-1);
                break;
            }
        }        
    }
    answer.push_back(0);
    return answer;
}

int main()
{
    vector<int> input1(5);

    input1[0] = 1;
    input1[1] = 2;
    input1[2] = 3;
    input1[3] = 2;
    input1[4] = 3;

    for (int a : solution(input1)) {
        cout << a << " ";
    }
}
