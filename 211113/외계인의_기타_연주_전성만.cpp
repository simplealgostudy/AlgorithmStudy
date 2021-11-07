#include <bits/stdc++.h>
using namespace std;
stack<int> stk[7];
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, p; cin >> n >> p;
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        if (stk[a].empty()) {
            ++answer;
            stk[a].push(b);
        } else {
            if (stk[a].top() < b) {
                ++answer;
                stk[a].push(b);
            } else if (stk[a].top() == b) {
                continue;
            } else {
                while (!stk[a].empty() && stk[a].top() > b) {
                    stk[a].pop();
                    ++answer;
                }
                if (stk[a].empty() || (!stk[a].empty() && stk[a].top() != b)) {
                    stk[a].push(b);
                    ++answer;
                }
            }
        }
    }
    cout << answer;
    return 0;
}
