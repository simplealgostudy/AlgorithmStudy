#include <bits/stdc++.h>
using namespace std;
struct p
{
    int y, x, l;
    bool operator <(const p &a) const
    {
        return l > a.l;
    }  
};
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<long long>> v(N);
    vector<vector<bool>> chk(N);
    map<long long, vector<pair<int, int>>> m;
    priority_queue<p> q;
    for (int i = 0; i < N; i++) 
    {
        int K; cin >> K;
        vector<bool> c_chk(K, false);
        vector<long long> num(K);
        chk[i] = c_chk;
        for (int j = 0; j < K; j++) 
        {
            long long a; cin >> a;
            num[j] = a;
            m[a].push_back({i, j});
        }
        v[i] = num;
    }
    long long g; cin >> g;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < v[i].size(); j++) 
        {
            if (g == v[i][j])
            {
                q.push({i, j, 0});
                chk[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        p cur = q.top();
        q.pop();
        if (v[cur.y][cur.x] == 0)
        {
            cout << cur.l;
            return 0;
        }
        if (v[cur.y].size() > cur.x + 1 && !chk[cur.y][cur.x+1])
        {
            chk[cur.y][cur.x+1] = 1;
            q.push({cur.y, cur.x + 1, cur.l});
        }
        else if (v[cur.y].size() == cur.x + 1 && v[cur.y][cur.x] == v[cur.y][0] && !chk[cur.y][0])
        {
            chk[cur.y][0] = 1;  
            q.push({cur.y, 0, cur.l});
        }
        if (0 <= cur.x - 1 && !chk[cur.y][cur.x-1])
        {
            chk[cur.y][cur.x-1] = 1;
            q.push({cur.y, cur.x - 1, cur.l});
        }
        else if (0 > cur.x - 1 && v[cur.y][cur.x] == v[cur.y][v[cur.y].size()-1] && !chk[cur.y][v[cur.y].size()-1])
        {
            chk[cur.y][v[cur.y].size() - 1] = 1;
            int tmp = v[cur.y].size() - 1;
            q.push({cur.y, tmp, cur.l});
        }
        for (pair<int, int> pii : m[v[cur.y][cur.x]])
        {
            if (!chk[pii.first][pii.second])
            {
                chk[pii.first][pii.second] = 1;
                q.push({pii.first, pii.second, cur.l+1});
            }
        }
    }
    cout << -1;
    return 0;
}
