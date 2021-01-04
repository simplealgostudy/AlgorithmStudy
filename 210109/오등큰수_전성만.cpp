#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    int arr[n];
    unordered_map<int ,int> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if(m.find(arr[i]) == m.end()) {
            m[arr[i]] = 1;
        } else {
            m.find(arr[i]) -> second ++;
        }
    }
    int res[n];
    res[n-1] = -1;
    stack<pair<int, int>> stk;
    stk.push({arr[n-1], m.find(arr[n-1])->second});
    for (int i = n - 2; i >= 0; i--) {
        while(!stk.empty() && stk.top().second <= m.find(arr[i])->second) stk.pop();
        if(!stk.empty()) {
            if(stk.top().second > m.find(arr[i])->second) {
                res[i] = stk.top().first;
                stk.push({arr[i], m.find(arr[i])->second});
            }
        } else {
            res[i] = -1;
            stk.push({arr[i], m.find(arr[i])->second});
        }
    }
    for (int i = 0; i < n; i++) cout << res[i] << ' ';
    return 0;
}