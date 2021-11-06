#include <bits/stdc++.h>
using namespace std;
int num[26];
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    string str; cin >> str;
    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        num[i] = m;
    }
    stack<long double> stk;
    for (auto s : str) {
        if (s >= 'A' && s <= 'Z') {
            stk.push(num[s - 'A']);
        } else {
            long double t1, t2;
            if (!stk.empty()) {
                t2 = stk.top();
                stk.pop();
            }
            if (!stk.empty()) {
                t1 = stk.top();
                stk.pop();
            }
            switch (s) {
                case '+': {
                    stk.push(t1 + t2);
                    break;
                }
                case '-': {
                    stk.push(t1 - t2);
                    break;
                }
                case '*': {
                    stk.push(t1 * t2);
                    break;
                }
                case '/': {
                    stk.push(t1 / t2);
                    break;
                }
            }
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << stk.top();
    return 0;
}