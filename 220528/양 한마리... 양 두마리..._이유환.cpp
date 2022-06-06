#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int H = 0, W = 0;
int answer = 0;

int move_w[4] = { 0, 0, -1, 1 };
int move_h[4] = { -1, 1, 0, 0 };

char g[101][101];

void dfs(int h, int w) {
	for (int i = 0; i < 4; i++) {
		int tmp_w = w + move_w[i];
		int tmp_h = h + move_h[i];
		if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < W && tmp_h < H) {
			if (g[tmp_h][tmp_w] == '#') {
				g[tmp_h][tmp_w] = '.';
				dfs(tmp_h, tmp_w);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int T = 0;
	cin >> T;

	for (int t = 0; t < T; t++) {
		answer = 0;

		cin >> H >> W;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> g[i][j];
			}
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (g[i][j] == '#') {
					g[i][j] == '.';
					answer++;
					dfs(i, j);
				}
			}
		}

		cout << answer << '\n';
	}

}
