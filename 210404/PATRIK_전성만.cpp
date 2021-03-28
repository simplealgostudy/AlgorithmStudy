#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    stack<pair<long long,long long >> stk;
    stk.push({v[0],1});
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] > stk.top().first) {
            int tmpNum = 0;
            while(!stk.empty()) {
                if (v[i] > stk.top().first) {
                    stk.pop();
                    tmpNum++;
                }
                else break;
            }
            if (!stk.empty() && stk.top().first == v[i]) {
                if (stk.size() - stk.top().second > 0) tmpNum++;
                tmpNum+=stk.top().second;
                stk.push({v[i], stk.top().second+1});
            } else {
                if (!stk.empty()) {
                    tmpNum++;
                }
                stk.push({v[i], 1});
            }
            ans += tmpNum;
        } else if (v[i] == stk.top().first) {
            ans += stk.top().second;
            if (stk.size() - stk.top().second > 0) ++ans;
            stk.push({v[i], stk.top().second+1});
        } else {
            ans += 1;
            stk.push({v[i], 1});
        }
    }
    cout << ans;
    return 0;
}