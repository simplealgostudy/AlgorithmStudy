#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int M = 0, N = 0, answer = 0;
char board[101][101];

int move_w[4] = { 0, 0, -1, 1 };
int move_h[4] = { -1, 1, 0, 0 };

void bfs(int h, int w) {
	queue<pair<int, int>> q;
	q.push(make_pair(h, w));

	int cnt = 1;
	board[h][w] = '.';
	while (!q.empty()) {
		int h = q.front().first;
		int w = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tmp_w = w + move_w[i];
			int tmp_h = h + move_h[i];
			if (tmp_w > 0 && tmp_h > 0 && tmp_w <= M && tmp_h <= N) {
				if (board[tmp_h][tmp_w] == '#') {
					board[tmp_h][tmp_w] = '.';
					cnt++;
					q.push(make_pair(tmp_h, tmp_w));
				}
			}
		}
	}

	if (answer < cnt) answer = cnt;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int K = 0;
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			board[i][j] = '.';
		}
	}

	for (int i = 0; i < K; i++) {
		int r = 0, c = 0;
		cin >> r >> c;
		board[r][c] = '#';
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == '#') {
				bfs(i, j);
			}
		}
	}

	cout << answer;
}
