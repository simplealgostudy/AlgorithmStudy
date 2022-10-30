#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R = 0, C = 0;
int K = 0, V = 0;

int answerK = 0, answerV = 0;

vector<vector<char>> v;
bool visit[251][251];

int move_w[4] = { 0, 0, 1, -1 };
int move_h[4] = { 1, -1, 0, 0 };

void dfs(int h, int w) {
	if (visit[h][w] == false) {
		visit[h][w] = true;

		if (v[h][w] == 'k') K++;
		else if (v[h][w] == 'v') V++;

		for (int i = 0; i < 4; i++) {
			int tmp_w = w + move_w[i];
			int tmp_h = h + move_h[i];
			if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < C && tmp_h < R) {
				if (!visit[tmp_h][tmp_w] && v[tmp_h][tmp_w] != '#') {
					
					dfs(tmp_h, tmp_w);
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
		vector<char> tmp;
		for (int j = 0; j < C; j++) {
			char c = '.';
			cin >> c;
			tmp.push_back(c);
		}
		v.push_back(tmp);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visit[i][j] && v[i][j] != '#') {
				dfs(i, j);

				if (K > V) answerK += K;
				else answerV += V;

				K = 0;
				V = 0;
			}
		}
	}

	cout << answerK << ' ' << answerV;

}
