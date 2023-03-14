#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int c; cin >> c;
    for (int i = 0; i < c; i++)
    {
        int a, b, t = 0; cin >> a >> b;
        queue<vector<int>> q;
        q.push({a, b, 0});
        while (!q.empty())
        {
            vector<int> v = q.front();
            q.pop();
            if (v[0] == v[1])
            {
                cout << v[2] << '\n';
                break;
            }
            if (v[0] + 1 <= v[1])
                q.push({v[0]+1, v[1], v[2] + 1});
            if (v[0]*2 <= v[1] + 3)
                q.push({v[0]*2, v[1] +3, v[2] + 1});
        }
    }
    return 0;
}
