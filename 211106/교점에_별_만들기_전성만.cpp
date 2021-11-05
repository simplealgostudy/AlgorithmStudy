#include <bits/stdc++.h>
using namespace std;
long long ep[4];
vector<string> solution(vector<vector<int>> line) {
    int m = line.size();
    vector<pair<long long, long long>> v;
    bool chk = false;
    for (int i = 0;  i < m - 1; ++i) {
        for (int j = i + 1; j < m; ++j) {
            long long a = line[i][0], b = line[i][1], e = line[i][2], c = line[j][0], d = line[j][1], f = line[j][2];
            if (!((a * d) - (b * c))) continue;
            long double x = ((long double)(b * f) - (e * d)) / (long double)((a * d) - (b * c));
            long double y = ((long double)(e * c) - (a * f)) / (long double)((a * d) - (b * c));
            if (x != (long long)x || y != (long long)y) continue;
            v.push_back({(long long)y, (long long)x});
            if (!chk) {
                ep[0] = (long long)x;
                ep[1] = (long long)y;
                ep[2] = (long long)x;
                ep[3] = (long long)y;
                chk = true;
            } else {
                ep[0] = min(ep[0], (long long)x);
                ep[1] = min(ep[1], (long long)y);
                ep[2] = max(ep[2], (long long)x);
                ep[3] = max(ep[3], (long long)y);
            }
        }
    }
    string tmp(ep[2] - ep[0] + 1, '.');
    vector<string> answer(ep[3] - ep[1] + 1, tmp);
    for (auto i : v) {
        answer[(ep[3]-ep[1]) - (i.first - ep[1])][(i.second - ep[0])] = '*';
    }
    return answer;
}