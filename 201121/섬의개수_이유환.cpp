#include <iostream>
#include <vector>
using namespace std;

int max_w = 0, max_h = 0;
int move_w[8] = { 0, 0, -1, 1, -1, 1, -1, 1};
int move_h[8] = { -1, 1, 0, 0, -1, -1, 1, 1};
vector<vector<int>> v;

void dfs(int h, int w) {
	if (v[h][w] == 1) {
		v[h][w] = 0;

		for (int i = 0; i < 8; i++) {
			int tmp_w = w + move_w[i];
			int tmp_h = h + move_h[i];
			if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < max_w && tmp_h < max_h) {
				if (v[tmp_h][tmp_w] == 1) {
					dfs(tmp_h, tmp_w);
				}
			}			
		}
	}
}

int main()
{
	int answer = 0;

	while (1) {
		cin >> max_w >> max_h;

		if (max_w == 0 && max_h == 0) break;

		for (int i = 0; i < max_h; i++) {
			vector<int> tmp_v(max_w);
			v.push_back(tmp_v);
		}

		int tmp = 0;
		for (int i = 0; i < max_h; i++) {
			for (int j = 0; j < max_w; j++) {
				cin >> tmp;
				v[i][j] = tmp;
			}
		}

		for (int i = 0; i < max_h; i++) {
			for (int j = 0; j < max_w; j++) {
				if (v[i][j] == 1) {					
					dfs(i, j);
					answer++;				
				}
			}
		}

		cout << answer << endl;

		answer = 0;
		v.clear();
	}
}
