#include <bits/stdc++.h>
using namespace std;

long long result = 0;

void dfs(vector<int> v, long long r)
{
    if (result < r)
    {
        result = r;
    }
    for(int i = 1; i < v.size() - 1; i++)
    {
        vector<int> tmp = v;
        tmp.erase(tmp.begin()+i);
        dfs(tmp, r + (v[i-1] * v[i+1]));
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    dfs(v, 0);
    cout << result;
    return 0;
}
