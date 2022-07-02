#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N = 0, M = 0;
vector<int> v[50001];
int visit[50001];
int m = 0;

int num = 0, dist = 0, cnt = 0;

void bfs() {
	queue<int> q;
	q.push(1);
	visit[1] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int there : v[node]) {
			if (!visit[there]) {
				visit[there] = visit[node] + 1;
				m = max(visit[there], m);
				q.push(there);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (m == visit[i]) {
			num = i;
			break;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (m == visit[i]) {
			cnt++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		int a = 0, b = 0;

		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs();

	cout << num << " " << m - 1 << " " << cnt;
}
