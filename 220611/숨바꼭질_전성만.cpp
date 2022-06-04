#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAX = 2e4 + 1;

int arr[MAX];
vector<int> v[MAX];

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m; cin >> n >> m;

    for (int i = 0 ; i < m ; i++)
    {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1 ; i <= n ; ++i)
    {
        arr[i] = (int) 1e9+1;
    }
    arr[1] = 0;

    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int val = arr[cur];

        for (auto c : v[cur])
        {
            if (val + 1 < arr[c])
            {
                arr[c] = val + 1;
                q.push(c);
            }
        }
    }
    
    int res = 0;
    vector<int> ans;

    for (int i = 1 ; i <= n ; ++i)
    {
        if (res < arr[i])
        {
            res = arr[i];
            ans.clear();
            ans.push_back(i);
        }
        else if (res == arr[i])
        {
            ans.push_back(i);
        }
    }

    cout << *ans.begin() << ' ' << arr[*ans.begin()] << ' ' << ans.size();

    return 0;
}
