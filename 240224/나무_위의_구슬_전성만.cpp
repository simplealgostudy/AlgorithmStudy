#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> v(n+1, vector<int>(2));
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }
    unsigned long long k;
    cin >> k;
    int curNode = 1;
    while (-1 != v[curNode][0] || -1 != v[curNode][1])
    {
        bool left = false;
        if (1 == k % 2) left = true;
        if (-1 == v[curNode][0] || -1 == v[curNode][1])
        {
            curNode = (-1 == v[curNode][0] ? v[curNode][1] : v[curNode][0]);
        }
        else if (left)
        {
            k = (k / 2) + 1;
            curNode = v[curNode][0];
        }
        else
        {
            k = k / 2;
            curNode = v[curNode][1];
        }
    }
    cout << curNode;
    return 0;
}
