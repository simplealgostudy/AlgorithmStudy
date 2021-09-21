#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> g[1001];
vector<bool> visit(1001);

void dfs(int idx) {
	visit[idx] = true;
	for (int i = 0; i < g[idx].size(); i++) {
		int tmp = g[idx][i];
		if (!visit[tmp]) {
			dfs(tmp);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int n = 0, m = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u = 0, v = 0;
		cin >> u >> v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			dfs(i);
			answer++;
		}
	}

	cout << answer;
}
