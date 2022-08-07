#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int move_w[2] = {0, 1};
int move_h[2] = {1, 0};

int g[65][65];
bool visit[65][65];

int N = 0;
bool sw = false;

void dfs(int h, int w) {

	if (g[h][w] == -1) {
		sw = true;
		return;
	}

	for (int i = 0; i < 2; i++) {
		int tmp_h = h + move_h[i] * g[h][w];
		int tmp_w = w + move_w[i] * g[h][w];	
		if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < N && tmp_h < N && !visit[tmp_h][tmp_w]) {
			visit[tmp_h][tmp_w] = true;
			dfs(tmp_h, tmp_w);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> N;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			cin >> g[i][j];
		}
	}

	visit[0][0] = true;
	dfs(0, 0);
	
	if (sw) cout << "HaruHaru"; 
	else cout << "Hing";
}
