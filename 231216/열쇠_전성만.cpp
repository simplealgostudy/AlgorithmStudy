#include <bits/stdc++.h>
using namespace std;

struct p
{
    int y, x;
};

struct dat
{
    int &h;
    int &w;
    int &curKey;
    vector<vector<bool>> &chk;
    unordered_map<char, vector<p>> &keym;
    vector<string> &v;
};

int bfs(int y, int x, dat d)
{
    int answer = 0;
    
    int pos[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    queue<p> q;
    q.push({y, x});
    d.chk[y][x] = true;
    while (false == q.empty())
    {
        int y_ = q.front().y;
        int x_ = q.front().x;
        q.pop();
        if (isupper(d.v[y_][x_]))
        {
            if (0 == (d.curKey & (1 << (d.v[y_][x_]-'A'))))
            {
                d.keym[(1<<(d.v[y_][x_]-'A'))].push_back({y_,x_});
                continue;
            }
        }
        else if (islower(d.v[y_][x_]))
        {
            if (0 == (d.curKey & (1<<(d.v[y_][x_]-'a'))))
            {
                d.curKey += (1<<(d.v[y_][x_]-'a'));
                while (!d.keym[(1<<(d.v[y_][x_]-'a'))].empty())
                {
                    p backm = d.keym[(1<<(d.v[y_][x_]-'a'))].back(); 
                    q.push(backm);
                    d.chk[backm.y][backm.x] = true;
                    d.keym[(1<<(d.v[y_][x_]-'a'))].pop_back();
                }
            }
        } 
        else if ('$' == d.v[y_][x_])
        {
            answer++;
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = y_ + pos[i][0];
            int nx = x_ + pos[i][1];
            if (ny < 0 || ny >= d.h || nx < 0 || nx >= d.w || true == d.chk[ny][nx] || '*' == d.v[ny][nx]) continue;
            d.chk[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    return answer;
}

int sol()
{
    int h, w; cin >> h >> w;
    vector<string> v(h);
    vector<vector<bool>> chk(h, vector<bool>(w, false));
    unordered_map<char, vector<p>> keym;
    for (int i = 0; i < h; i++) cin >> v[i];
    string key; cin >> key;
    int curKey = 0;
    int ans = 0;
    if ("0" != key)
    {
        for (auto c : key)
            curKey += (1<<(c-'a'));
    }
    dat d = {h,w,curKey,chk,keym,v};
    for (int i = 0; i < h; i++)
    {
        if (false == chk[i][0] && '*' != v[i][0])
            ans += bfs(i, 0, d);
        if (false == chk[i][w-1] && '*' != v[i][w-1])
            ans += bfs(i, w-1, d);
    }
    for (int i = 0; i < w; i++)
    {
        if (false == chk[0][i] && '*' != v[0][i])
            ans += bfs(0, i, d);
        if (false == chk[h-1][i] && '*' != v[h-1][i])
            ans += bfs(h-1, i, d); 
    }
    return ans;
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) 
    {
        cout << sol() << '\n';
    }
    return 0;
}
