#include <bits/stdc++.h>
using namespace std;

int res = 0;

void dfs(vector<pair<int, int>> p, int index, int cnt) 
{
	if (index == p.size()) 
    {
		if (res < cnt) res = cnt;

		return;
	}
	if (p[index].first <= 0) 
    {
		dfs(p, index + 1, cnt);
        
		return;
	}
	for (int i = 0; i < p.size(); ++i) 
    {
		if (i == index) continue;

		if (p[i].first > 0) 
        {
			vector<pair<int, int>> tmp = p;
			tmp[i].first -= tmp[index].second;
			tmp[index].first -= tmp[i].second;
			int tcnt = 0;

			if (tmp[i].first <= 0) tcnt++;
			if (tmp[index].first <= 0) tcnt++;

			dfs(tmp, index + 1, cnt + tcnt);
		} 
        else 
        {
			dfs(p, index + 1, cnt);
		}
	}
	return;
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int n; cin >> n;
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
	dfs(p, 0, 0);

	cout << res;	

    return 0;
} 