#include <bits/stdc++.h>
using namespace std;

const int upperNum = 31650;
map<int, int> prime;
bool isPrime(int n)
{
    for (int i = 2; i < sqrt(n + 1); i++)
    {
        if (0 == n % i)
        {
            return false;
        }
    }
    return true;
}

void divPrime(int a, unordered_map<int, int> &um)
{
    for (auto it = prime.begin(); it != prime.end(); it++)
    {
        if (a < it->first) { return; }
        if (0 != a % it->first) { continue; }
        um[it->first]++;
        divPrime(a / it->first, um);
        return;
    }
    um[a] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int MOD = 1e9;
    bool vis[upperNum+1];
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i <= upperNum; i++)
    {
        if (vis[i]) { continue; }
        if (false == isPrime(i)) { continue; }
        for (auto it = i; it <= upperNum; it *= i)
        {
            vis[it] = 1;
            prime[it] = 1;
        }
    }
    int n;
    cin >> n;
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        divPrime(a, um);
    }
    int m;
    cin >> m;
    unordered_map<int, int> um2;
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        divPrime(b, um2);
    }
    bool upper = false;
    long long ans = 1;
    for (auto it = um.begin(); it != um.end(); it++)
    {
        if (um2.find(it->first) == um2.end()) {continue;}
        int p = min(it->second, um2[it->first]);
        while (p--)
        {
            ans *= it->first;
            if (ans < MOD) { continue; }
            upper = true;
            ans %= MOD;
        }
    }
    string str = to_string(ans);
    string up((upper? 9 - str.size() : 0), '0');
    cout << (up + str);

    return 0;
}
