#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string t = "12348765";
    string c = "";
    for (int i = 0; i < 4; i++)
    {
        int a; cin >> a; c += (a + '0');
    }
    string tmp = "";
    for (int i = 0; i < 4; i++)
    {
        int a; cin >> a;
        tmp = to_string(a) + tmp;
    }
    c += tmp;
    queue<string> q;
    map<string, int> m;
    q.push(t);
    m[t] = 1;
    int r = 0;
    while (!q.empty())
    {
        int si = q.size();
        while(si--)
        {
            string cur = q.front();
            q.pop();
            if (cur == c)
            {
                cout << r;
                return 0;
            }
            string next = cur;
            for (int i = 0; i < 4; i++)
            {
                swap(next[i], next[i+4]);
            }
            if (m.find(next) == m.end())
            {
                m[next] = 1;
                q.push(next);
            }
            next = cur;
            auto tmpt = next[3];
            auto tmpt2 = next[7];
            for (int i = 3; i > 0; i--)
            {
                next[i] = next[i-1];
                next[i+4] = next[i+3];
            }
            next[0] = tmpt;
            next[4] = tmpt2;
            if (m.find(next) == m.end())
            {
                m[next] = 1;
                q.push(next);
            }
            next = cur;
            tmpt = next[1];
            next[1] = next[2];
            next[2] = next[6];
            next[6] = next[5];
            next[5] = tmpt;
            if (m.find(next) == m.end())
            {
                m[next] = 1;
                q.push(next);
            }
            next = cur;
            swap(next[0], next[7]);
            if (m.find(next) == m.end());
            {
                m[next] = 1;
                q.push(next);
            }
        }
        r++;
    }

    return 0;
}
