#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> g;
int n = 0, m = 0;

int move_w[4] = { 0, 0, -1, 1};
int move_h[4] = { -1, 1, 0, 0};

void airDfs(int h, int w, bool choice) {
	if (g[h][w] == 0) {
		if (choice == 0) {
			g[h][w] = 2;
		}
		else g[h][w] = 4;
				
		for (int i = 0; i < 4; i++) {
			int tmp_w = w + move_w[i];
			int tmp_h = h + move_h[i];
			if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < m && tmp_h < n) {
				if (g[tmp_h][tmp_w] == 0) {
					airDfs(tmp_h, tmp_w, choice);
				}			
			}
		}
	}
}

void choiceDfs(int h, int w) {
	if (g[h][w] == 1) {
		int tmp = 0;
		g[h][w] = 3;
		if (g[h + 1][w] == 2) tmp++;
		if (g[h - 1][w] == 2) tmp++;
		if (g[h][w + 1] == 2) tmp++;
		if (g[h][w - 1] == 2) tmp++;

		if (tmp >= 2) {
			g[h][w] = 4;
			
			for (int i = 0; i < 4; i++) {
				int tmp_w = w + move_w[i];
				int tmp_h = h + move_h[i];
				if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < m && tmp_h < n) {
					if (g[tmp_h][tmp_w] == 0) {
						airDfs(tmp_h, tmp_w, 1);
					}
				}
			}
		}
		
		for (int i = 0; i < 4; i++) {
			int tmp_w = w + move_w[i];
			int tmp_h = h + move_h[i];
			if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < m && tmp_h < n) {
				if (g[tmp_h][tmp_w] == 1) {
					choiceDfs(tmp_h, tmp_w);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	int start1 = 0, start2 = 0;

	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		for (int j = 0; j < m; j++) {
			int c = 0;
			cin >> c;
			tmp.push_back(c);
		}
		g.push_back(tmp);
	}

	airDfs(0, 0, 0);
	int swCount = 0;
	int answer = 0;

	while (1) {		
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (g[i][j] == 1) {
					choiceDfs(i, j);
					swCount++;
				}				
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (g[i][j] == 4) g[i][j] = 2;
				else if (g[i][j] == 3) g[i][j] = 1;
			}
		}

		if (swCount == 0) break;
		else answer++;
		swCount = 0;
	
	}
	
	cout << answer;
}
