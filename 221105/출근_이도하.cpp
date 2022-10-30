#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int R = 0, C = 0;

queue<pair<int, int>> q;
vector<vector<bool>> v;
int visit[1001][1001];

int N = 0;

int move_h[11];
int move_w[11];

int answer = -1;

void bfs() {
	while (!q.empty()) {
		int h = q.front().first;
		int w = q.front().second;
		q.pop();

		if (h == R - 1) {
			answer = visit[h][w];
			break;
		}

		for (int i = 0; i < N; i++) {
			int tmp_h = h + move_h[i];
			int tmp_w = w + move_w[i];

			if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < C && tmp_h < R) {
				if (visit[tmp_h][tmp_w] == -1 && v[tmp_h][tmp_w]) {
					q.push(make_pair(tmp_h, tmp_w));
					visit[tmp_h][tmp_w] = visit[h][w] + 1;					
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		vector<bool> tmp;
		for (int j = 0; j < C; j++) {
			int n = 0;
			cin >> n;

			tmp.push_back(n);
			visit[i][j] = -1;
		}
		v.push_back(tmp);
	}

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> move_h[i] >> move_w[i];
	}

	for (int i = 0; i < C; i++) {
		if (v[0][i]) {
			q.push(make_pair(0, i));
			visit[0][i] = 0;
		}
	}

	bfs();

	cout << answer;

}
