#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    int i = 0;
    int j = 0;

    for (i = 1; i < yellow; i++) {
        if (yellow % i == 0)
            j = yellow / i;
        if ((i + 2) * (j + 2) - yellow == brown) {
            answer.push_back(j + 2);
            answer.push_back(i + 2);
            return answer;
        }
    }
}
