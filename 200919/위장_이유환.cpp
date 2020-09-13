#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;

    int answer = 1;

    for (int i = 0; i < clothes.size(); i++) {
        if (m.find(clothes[i][1]) == m.end()) { // 맵이 비었으면
            m[clothes[i][1]] = 1;
        }
        else { // 비어있지 않으면
            m[clothes[i][1]]++;
        }   
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        answer *= it->second + 1; //+ 1 은 그 옷을 입지 않았을 경우
    }
    return answer - 1; //"모든 옷을 입지 않았을 경우" 는 스파이는 무조건 하나 이상의 옷을 입으므로 - 1을 해줌
}
