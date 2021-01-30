#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
int n, m, result, sum;
int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(vector<vector<int>> &vp, vector<vector<bool>> &chk, int x, int y) {
	for (int i = 0; i < 4; i++) {
		pair<int, int> next = {x + pos[i][0], y + pos[i][1]};
		if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m || chk[next.first][next.second]) continue;
		if (v[next.first][next.second]) {
			vp[next.first][next.second]++;
		} else {
			chk[next.first][next.second] = true;
			dfs(vp, chk, next.first, next.second);
		}
	}
}
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	v.resize(n, vector<int>(m));
	result = 0;
	sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if(v[i][j]) sum++;
		}
	}
	while(sum > 0) {
		vector<vector<int>> vp(n, vector<int>(m, 0));
		vector<vector<bool>> chk(n, vector<bool>(m, false));
		chk[0][0] = true;
		dfs(vp, chk, 0, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vp[i][j] >= 2) {
					v[i][j] = 0;
					sum--;
				}
			}
		}
		result++;
	}
	cout << result;
	return 0;
}
