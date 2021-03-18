//https://programmers.co.kr/learn/courses/30/lessons/42842
/*
brown = 14
yellow = 4
bbbbbb
byyyyb
bbbbbb
--> return[6,3]
 
brown = 12
yellow = 4
bbbb
byyb
byyb
bbbb
--> return[4,4]
 
brown = 24
yellow = 24
bbbbbbbb
byyyyyyb
byyyyyyb
byyyyyyb
byyyyyyb
bbbbbbbb
--> return [8, 6]
 
yellow가 두 수의 곱으로 이루어져 있다고 가정합니다. --> if문으로 구현합니다.
두 수 yellow_i, yellow_j (단, yellow_i>=yellow_j)가 있을 때 --> if문으로 구현합니다.
얇은 가로선 길게 2개 (맨 윗 라인 전부 다) --> brown_row
얇은 세로선 2개 (맨 위 맨 아래 라인을 제외한 세로) --> brown_col
brown_row = yellow_i+2   |
brown_col = yellow_j     |--> if문으로 구현합니다.
를 만족하는 값을 찾으면 됩니다.
 
 
*/
#include <string>
#include <vector>
//#include <iostream>
//40분
using namespace std;
vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    int yellow_i, yellow_j;
    int brown_row, brown_col;
//반복문 yellow_i와 yellow_j의 최대 범위 수는 yellow보다 클 순 없으므로 yellow로 했습니다.
    for (yellow_i = 1; yellow_i <= yellow; yellow_i++)
    {
        for (yellow_j = 1; yellow_j <= yellow; yellow_j++)
        {
            if (yellow_i * yellow_j == yellow)
            {
                if (yellow_i >= yellow_j)
                {
                    brown_row = yellow_i + 2;
                    brown_col = yellow_j;
                    if (brown_row * 2 + brown_col * 2 == brown)
                    {
                        answer.push_back(yellow_i + 2);
                        answer.push_back(yellow_j + 2);
                        return answer;
                    }
                }
            }
        }
    }
}
// int main(){
//     int brown = 8;
//     int yellow = 1;
//     solution(brown, yellow);
// }

