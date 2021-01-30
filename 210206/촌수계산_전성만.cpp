#include <bits/stdc++.h>
using namespace std;
int res = -1;
int res2;
vector<int> v[101];
void dfs(vector<bool> chk, int pos, int count) {
	if (pos == res2) {
		res = count;
		return;
	}
	for (int i = 0; i < v[pos].size(); i++) {
		if (chk[v[pos][i]]) continue;
		chk[v[pos][i]] = true;
		dfs(chk, v[pos][i], count + 1);
		chk[v[pos][i]] = false;
	}
}
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, res1, m; cin >> n >> res1 >> res2 >> m;
	vector<bool> chk(n+1, false);
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	chk[res1] = true;
	dfs(chk, res1, 0);
	cout << res;
	return 0;
}
