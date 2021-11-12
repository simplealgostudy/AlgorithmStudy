#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> vp, v;
    int y1, x1; 
    bool start = true;
    while (start) {
        cin >> x1 >> y1;
        v.push_back({x1, y1});
        if (y1 < 0) start = 0;
    }
    bool chk = false;
    int tmpx, backy = y1, backx = x1;
    for (int i = 0; i < n; ++i) {
        int y, x;
        if (i < n-v.size()) cin >> x >> y;
        else {
            x = v[i-n+v.size()].first;
            y = v[i-n+v.size()].second;
        }
        if (backx == x && ((backy > 0 && y <= 0) || (backy <= 0 && y > 0))) {
            if (!chk) {
                chk = 1;
                tmpx = x;
            } else {
                chk = 0;
                if (tmpx < x) {
                    vp.push_back({tmpx, x});
                } else {
                    vp.push_back({x, tmpx});
                }
            }
        }
        backx = x;
        backy = y;
    }
    sort(vp.begin(), vp.end());
    stack<pair<int, int>> stk1, stk2;
    long long ans1 = 0, ans2 = 0;
    pair<int, int> back;
    bool bchk1 = false;
    for (auto s : vp) {
        if (!bchk1) {
            bchk1 = 1;
            back = s;
            ans1++;
        } else {
            if (back.second > s.first) continue;
            else {
                back = s;
                ans1++;
            }
        }
    }
    stack<pair<int,int>> stk;
    for (auto s : vp) {
        if (stk.empty()) {
            stk.push(s);
        } else {
            while (!stk.empty() && s.first < stk.top().second) {
                stk.pop();
            }
            stk.push(s);
        }
    }
    cout << ans1++ << ' ' << stk.size();
    return 0;
}
