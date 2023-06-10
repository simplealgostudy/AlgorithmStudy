#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int n = 0, m = 0, k = 0, answer = 0;
vector<int> v[101];
bool visit[101];

void dfs(int depth, int idx) {
	if (depth == n) {
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			bool flag = true;
			for (int j = 0; j < k; j++) {
				if (!visit[v[i][j]]) {
					flag = false;
					break;
				}
			}
			
			if (flag) cnt++;

		}

		answer = max(answer, cnt);
		return;
	}

	for (int i = idx; i <= (n * 2); i++) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(depth + 1, i + 1);
			visit[i] = false;
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			int s = 0;
			cin >> s;
			v[i].push_back(s);
		}
	}

	dfs(0, 0);

	cout << answer;
}
