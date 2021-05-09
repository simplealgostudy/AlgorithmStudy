#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer = {0, 0};
    int zero = 0;
    for (auto i : lottos) if (!i) zero++;
    map<int, int> m;
    for (auto i : win_nums) {
        m[i] = i;
    }
    int cnt = 0;
    for (auto i : lottos) {
        if (m.find(i) != m.end()) cnt++;
    }
    int first = zero + cnt;
    answer[0] = 7 - first;
    if (answer[0] > 5) {
        answer[0] = 6;
    }
    answer[1] = 7 - cnt;
    if (answer[1] > 5) {
        answer[1] = 6;
    }
    return answer;
}