#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; 
    cin >> n >> m;
    priority_queue<int> c;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        c.push(tmp);
    }
    for (int j = 0; j < m && !c.empty(); j++) {
        int tmp;
        cin >> tmp;
        if (tmp > c.top()) {
            cout << 0;
            return 0;
        }
        tmp = c.top() - tmp;
        c.pop();
        if (tmp > 0)
            c.push(tmp);
    }
    cout << 1;
    return 0;
}