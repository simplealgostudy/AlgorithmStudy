#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N = 0;
int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
int answer = -1;
int move_w[6] = { -1, 1, -2, 2, -1, 1};
int move_h[6] = { -2, -2, 0, 0, 2, 2};
vector<vector<int>> v;
void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(r1, c1), 0));

	while (!q.empty()) {
		int h = q.front().first.first;
		int w = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		v[h][w] = 1;

		if (h == r2 && w == c2) {
			answer = cnt;
			break;
		}

		for (int idx = 0; idx < 6; idx++) {
			int tmp_w = w + move_w[idx];
			int tmp_h = h + move_h[idx];
			if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < N && tmp_h < N) {
				if (v[tmp_h][tmp_w] == 0) {
					v[tmp_h][tmp_w] = 1;
					q.push(make_pair(make_pair(tmp_h, tmp_w), cnt + 1));
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> N;
	cin >> r1 >> c1 >> r2 >> c2;
	for (int i = 0; i <= N; i++) {
		vector<int> tmp;
		for (int j = 0; j <= N; j++) {
			tmp.push_back(0);
		}
		v.push_back(tmp);
	}

	bfs();

	cout << answer;
}
