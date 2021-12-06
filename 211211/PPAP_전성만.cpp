#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str; cin >> str;
    string ans = "";
    stack<char> stk;
    int idx = 0;
    while (idx < str.size()) {
        if (!stk.empty() && stk.size() > 1 && idx != str.size() && str[idx] == 'A' && str[idx+1] == 'P' && stk.top() == 'P') {
            stk.pop();
            if (!stk.empty() && stk.top() == 'P') {
                idx++;
            } else {
                stk.push('P');
                stk.push('A');
            }
        } else stk.push(str[idx]);
        idx++;
    }
    cout << ((stk.size() == 1 && stk.top() == 'P')?"PPAP":"NP");
    return 0;
}
