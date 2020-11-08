#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int a, b, n, m; 
    cin >> a >> b >> n >> m;

    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));

    bool chk[100001];
    memset(chk, false, sizeof(chk));

    chk[n] = true;
    int case_t[8] = {1, -1, a, -a, b, -b, n*a, n*b};

    while (!q.empty()) 
    {
        pair<int, int> cur = q.front();
        case_t[6] = cur.first*a;
        case_t[7] = cur.first*b;
        q.pop();

        if (cur.first == m) 
        {
            cout << cur.second;
            return 0;
        }

        int next_p;
        for (int i = 0; i < 8; i++) 
        {
            if(i >= 0 && i <= 5) next_p = cur.first + case_t[i];
            if (i == 6 || i == 7) next_p = case_t[i];

            if(next_p < 0 || next_p > 1e5 || chk[next_p]) continue;

            chk[next_p] = true;
            q.push(make_pair(next_p, cur.second+1));
        }
    }

    return 0;
}