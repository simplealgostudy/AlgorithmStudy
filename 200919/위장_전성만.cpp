#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) 
{
    ios::sync_with_stdio(false);
    int answer = 1;
    
    set<string> s;              // 중복 제거
    vector<string> v;           // 의상의 종류 만 수집
    
    for(auto i : clothes)
    {
        s.insert(i[1]);
        v.emplace_back(i[1]);
    }
    
    for(auto i : s) 
    {
        answer *= count(v.begin(), v.end(), i) + 1; // count함수를 사용하여 의상 종류의 개수를 얻는다.
    }
    
    return answer - 1; // 모두 없을 경우를 제외하여 -1을 한다.
}