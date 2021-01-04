#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str; cin >> str;
    if (str.size() % 2) {
        cout << 0;
        return 0;
    }
    int res[17][2];
    for (int i = 0; i < 17; i++) for (int j = 0; j < 2; j++) res[i][j] = 1;
    stack<char> stk;
    int j = 0;
    for (int i = 0; i < str.size(); i++) {
        switch (str[i]) {
            case '(':
                stk.push(str[i]);
                res[++j][0] = 2;
                break;
            case '[':
                stk.push(str[i]);
                res[++j][0] = 3;
                break;
            case ')':
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                    res[j][0] = res[j+1][1] * res[j][0];
                    if (res[j][1] == 1) res[j][1] = res[j][0];
                    else res[j][1] += res[j][0];
                    res[j+1][1] = 1;
                    res[j--][0] = 0;
                } else {
                    cout << 0;
                    return 0;
                }
                break;
            case ']':
                if (!stk.empty() && stk.top() == '[') {
                    stk.pop();
                    res[j][0] = res[j+1][1] * res[j][0];
                    if (res[j][1] == 1) res[j][1] = res[j][0];
                    else res[j][1] += res[j][0];
                    res[j+1][1] = 1;
                    res[j--][0] = 0;
                } else {
                    cout << 0;
                    return 0;
                }
                break;
        }
    }
    if (!stk.empty()) cout << 0;
    else cout << res[1][1];
    return 0;
}