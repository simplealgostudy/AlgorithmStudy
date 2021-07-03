#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N = 0, M = 0;
int move_w[4] = { 0, 0, -1, 1};
int move_h[4] = { -1, 1, 0, 0};
vector<vector<int>> v;
int bfs() {
	vector<vector<bool>> visit(N, vector<bool>(M, false));

	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 2 && visit[i][j] == false) {
				visit[i][j] = true;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));

				int cnt = 0;
				bool sw = true;
				while (!q.empty()) {
					cnt++;
					int h = q.front().first;
					int w = q.front().second;
					q.pop();
					for (int idx = 0; idx < 4; idx++) {
						int tmp_w = w + move_w[idx];
						int tmp_h = h + move_h[idx];
						if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < M && tmp_h < N) {
							if (v[tmp_h][tmp_w] == 2 && visit[tmp_h][tmp_w] == false) {
								visit[tmp_h][tmp_w] = true;
								q.push(make_pair(tmp_h, tmp_w));
							}
							else if (v[tmp_h][tmp_w] == 0) sw = false;
						}
					}
				}

				if (sw) sum += cnt;
			}
		}
	}

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> N >> M;

	vector<pair<int, int>> zero;
	
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < M; j++) {
			int n = 0;
			cin >> n;
			
			tmp.push_back(n);
			if (n == 0) zero.push_back(make_pair(i, j));
		}
		v.push_back(tmp);
	}

	int answer = 0;
	for (int i = 0; i < zero.size(); i++) {
		for (int j = 0; j < zero.size(); j++) {
			if (i != j) {
				int tmpH = zero[i].first;
				int tmpW = zero[i].second;
				int tmpH2 = zero[j].first;
				int tmpW2 = zero[j].second;

				v[tmpH][tmpW] = 1;
				v[tmpH2][tmpW2] = 1;

				int cnt = bfs();
				if(answer < cnt) answer = cnt;

				v[tmpH][tmpW] = 0;
				v[tmpH2][tmpW2] = 0;
			}
		}
	}
	
	cout << answer;
}
