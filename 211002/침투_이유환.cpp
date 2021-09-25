#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int M = 0, N = 0;
char board[1001][1001];

int move_w[4] = { 0, 0, -1, 1 };
int move_h[4] = { -1, 1, 0, 0 };
int startH = 0, startW = 0;

void bfs(int h, int w) {
	int time = 0;
	int check[21][21] = { 0 };
	bool visit[21][21] = { false };

	visit[h][w] = true;

	vector<pair<int, int>> fishV;
	vector<int> fishDisp;
	queue<pair<int, int>> q;
	q.push(make_pair(h, w));

	while (!q.empty()) {
		int h = q.front().first;
		int w = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tmp_w = w + move_w[i];
			int tmp_h = h + move_h[i];
			if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < N && tmp_h < M) {
				if (board[tmp_h][tmp_w] == '0') {
					board[tmp_h][tmp_w] = '.';
					q.push(make_pair(tmp_h, tmp_w));
				}
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		string value = "";
		cin >> value;

		for (int j = 0; j < N; j++) {
			board[i][j] = value[j];
		}
	}
	
	for (int j = 0; j < N; j++) {
		bfs(0, j);
	}

	string answer = "NO";
	for (int j = 0; j < N; j++) {
		if (board[M - 1][j] == '.') answer = "YES";
	}

	cout << answer;
}
