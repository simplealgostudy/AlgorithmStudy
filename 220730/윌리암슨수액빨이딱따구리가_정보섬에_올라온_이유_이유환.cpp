#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int move_h[4] = { -1, 1, 0, 0 };
int move_w[4] = { 0, 0, -1, 1 };

queue<pair<pair<int, int>, int>> q;
int n = 0, m = 0;
int g[3001][3001];
bool visit[3001][3001];

int answer = -1;

void bfs() {

	while(!q.empty()) {
		int h = q.front().first.first;
		int w = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tmp_w = w + move_w[i];
			int tmp_h = h + move_h[i];
			if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < m && tmp_h < n && !visit[tmp_h][tmp_w] && g[tmp_h][tmp_w] != 1) {
				if (g[tmp_h][tmp_w] == 3 || g[tmp_h][tmp_w] == 4 || g[tmp_h][tmp_w] == 5) {
					answer = cnt + 1;
					return;
				}

				visit[tmp_h][tmp_w] = true;
				q.push(make_pair(make_pair(tmp_h, tmp_w), cnt + 1));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string tmp = "";
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++) {
			g[i][j] = tmp[j] - 48;

			if (g[i][j] == 2) q.push(make_pair(make_pair(i, j), 0));
		}
	}

	bfs();

	if (answer == -1) cout << "NIE";
	else cout << "TAK" << '\n' << answer;
}
