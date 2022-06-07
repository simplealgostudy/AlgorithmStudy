#include <bits/stdc++.h>
using namespace std;

bool arr[21][21], chk[21][21];
int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct th 
{
    int dist, y, x;
};

bool comp(th a, th b)
{
    if (a.dist != b.dist)
    {
        return a.dist < b.dist;
    }
    else if (a.y != b.y)
    {
        return a.y < b.y;
    }
    else
    {
        return a.x < b.x;
    }
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; ++i)
    {
        for (int j = 1 ; j <= n ; ++j)
        {
            cin >> arr[i][j];
        }
    }
    pair<int, int> start, goal;
    cin >> start.first >> start.second;
    map<pair<int, int>, pair<int, int>> um;
    for (int i = 0 ; i < m ; ++i)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        um[{a, b}] = {c, d};
    }
    vector<th> v;
    for (int t = m ; t > 0 ; --t)
    {
        v.clear();
        for (int p = 0 ; p <= 1 ; ++p) 
        {
            memset(chk, 0, sizeof(chk));
            queue<th> q;
            q.push({0, start.first, start.second});
            chk[start.first][start.second] = 1;
            th cur;
            while (!q.empty())
            {
                cur = q.front();
                q.pop();
                if (0 == p) 
                {
                    if (um.find({cur.y, cur.x}) != um.end())
                    {
                        v.push_back(cur);
                        if (t == v.size())
                        {
                            break;
                        }
                    }
                }
                else
                {
                    if (goal.first == cur.y && goal.second == cur.x)
                    {
                        break;
                    }
                }
                for (int i = 0 ; i < 4 ; ++i)
                {
                    th next = {cur.dist + 1, cur.y + pos[i][0], cur.x + pos[i][1]};
                    if (next.y < 1 || next.y > n || next.x < 1 || next.x > n || arr[next.y][next.x] || chk[next.y][next.x]) continue;
                    chk[next.y][next.x] = 1;
                    q.push(next);
                }
            }
            if (0 == p)
            {
                sort(v.begin(), v.end(), comp);
                if (t != v.size())
                {
                    cout << -1;
                    return 0;
                }
                if (v.begin()->dist > k) {
                    cout << -1;
                    return 0;
                }
                k -= v.begin()->dist;
                start.first = v.begin()->y;
                start.second = v.begin()->x;
                goal = um[start];
                um.erase(start);
            }
            else
            {
                start = goal;
                if (cur.dist > k)
                {
                    cout << -1;
                    return 0;
                }
                else
                {
                    k += cur.dist;
                }
            }
        }
    }
    cout << k;
    return 0;
}
