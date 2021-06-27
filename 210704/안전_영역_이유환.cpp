#include <iostream>
#include <vector>
using namespace std;

int N = 0;
int move_w[8] = { 0, 0, -1, 1};
int move_h[8] = { -1, 1, 0, 0};
vector<vector<int>> v;
vector<vector<bool>> visit;

void dfs(int h, int w, int max) {
	if (visit[h][w] == false) {
		visit[h][w] = true;

		for (int i = 0; i < 8; i++) {
			int tmp_w = w + move_w[i];
			int tmp_h = h + move_h[i];
			if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < N && tmp_h < N) {
				if (visit[tmp_h][tmp_w] == false && v[tmp_h][tmp_w] > max) {
					dfs(tmp_h, tmp_w, max);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> N;

	int max = 0;
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < N; j++) {
			int n = 0;
			cin >> n;

			if (max < n) max = n;
			tmp.push_back(n);
		}
		v.push_back(tmp);
	}

	int answer = 0;
	while(max--) {
		int cnt = 0;
		
		for (int i = 0; i < N; i++) {
			vector<bool> tmp;
			for (int j = 0; j < N; j++) {
				tmp.push_back(false);
			}
			visit.push_back(tmp);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == false && v[i][j] > max) {
					dfs(i, j, max);					
					cnt++;
				}
			}
		}

		if (answer < cnt) answer = cnt;
		visit.clear();
	}

	cout << answer;
}
