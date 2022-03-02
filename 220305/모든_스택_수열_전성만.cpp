#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
int n;
void dfs(vector<int> vi, stack<int> stk1, int c) {
    if (c == n + 1) {
        if (vi.size() == n) v.push_back(vi);
        return;
    }
    stk1.push(c);
    dfs(vi, stk1, c + 1);
    vector<int> tmp = vi;
    while (!stk1.empty()) {
        tmp.push_back(stk1.top());
        stk1.pop();
        dfs(tmp, stk1, c+1);
    }
}
int main() {
    scanf("%d", &n);
    vector<int> vi;
    stack<int> stk1;
    dfs(vi, stk1, 1);
    for (int i = v.size()-1; i >= 0; i--) {
        for (auto c : v[i]) {
            cout << c << ' ';
        }
        cout << '\n';
    }
    return 0;
}
