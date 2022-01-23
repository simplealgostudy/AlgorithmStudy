#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N = 0;
vector<int> v(11);
vector<vector<bool>> g(11, vector<bool>(11, false));
vector<int> a1, a2;

int answer = 12 * 102;

void bfs(vector<int> a1, vector<int> a2) {
	queue<int> q;

	bool visit1[11] = { false };
	bool visit2[11] = { false };

	if (a1.size() == 0 || a1.size() == N) {
		return;
	}

	q.push(a1[0]);
	
	int man1 = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		visit1[cur] = true;

		for (int i = 0; i < a1.size(); i++) {
			if (g[cur][a1[i]] && !visit1[a1[i]]) {
				q.push(a1[i]);
			}
		}
	}

	for (int i = 0; i < a1.size(); i++) {
		if (!visit1[a1[i]]) return;
		man1 += v[a1[i]];
	}

	if (a2.size() == 0 || a2.size() == N) {
		return;
	}

	q.push(a2[0]);

	int man2 = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		visit2[cur] = true;

		for (int i = 0; i < a2.size(); i++) {
			if (g[cur][a2[i]] && !visit2[a2[i]]) {
				q.push(a2[i]);
			}
		}
	}

	for (int i = 0; i < a2.size(); i++) {
		if (!visit2[a2[i]]) return;
		man2 += v[a2[i]];
	}

	answer = min(answer, abs(man1 - man2));
}

void dfs(int idx, vector<int> a1, vector<int> a2) {
	if (idx > N) {
		bfs(a1, a2);
		return;
	}

	a1.push_back(idx);
	dfs(idx + 1, a1, a2);
	a1.pop_back();

	a2.push_back(idx);
	dfs(idx + 1, a1, a2);
	a2.pop_back();
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= N; i++) {
		int n = 0;
		cin >> n;

		for (int j = 0; j < n; j++) {
			int tmp = 0;
			cin >> tmp;
			g[i][tmp] = true;
		}
	}

	dfs(1, a1, a2);

	if (answer == (12 * 102)) cout << -1;
	else cout << answer;
}
