#include <bits/stdc++.h>
using namespace std;
long long dfs(int x, unordered_map<int, vector<int>> &um, vector<bool> &chk)
{
  if (um[x].empty()) return 1;
  long long sum = 0;
  for (auto it : um[x])
  {
    if (chk[it]) continue;
    chk[it] = 1;
    sum += dfs(it, um, chk);
  }
  return sum + 1;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int n, m, x;
  cin >> n >> m >> x;
  unordered_map<int, vector<int>> upper, lower;
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    lower[a].push_back(b);
    upper[b].push_back(a);
  }
  vector<bool> lchk(n + 1, 0), rchk(n + 1, 0);
  lchk[x] = 1;
  rchk[x] = 1;
  long long l = dfs(x, lower, lchk);
  long long u = dfs(x, upper, rchk);
  cout << u << ' ' << (n-l+1);
  return 0;
}
