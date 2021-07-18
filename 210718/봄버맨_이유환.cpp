#include <iostream>
#include <vector>
using namespace std;

int move_w[4] = { -1, 1, 0, 0 };
int move_h[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int R = 0, C = 0, N = 0;

	cin >> R >> C >> N;

	vector<vector<char>> board;
	int tmpB[201][201];

	for (int i = 0; i < R; i++) {
		vector<char> tmp;
		for (int j = 0; j < C; j++) {
			char n = '.';
			cin >> n;

			tmp.push_back(n);
			if (n == 'O') {
				tmpB[i][j] = 1;
			}
			else tmpB[i][j] = -1;
		}

		board.push_back(tmp);
	}

	int cnt = 1;
	int start = 0;
	
	while (cnt < N) {
		vector<pair<int, int>> tmp;
		int size = 0;
		
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (tmpB[i][j] != -1) {
					size++;
					if (tmpB[i][j] < 3) {						
						tmpB[i][j]++;					
					}
					if (tmpB[i][j] == 3) {
						tmpB[i][j] = -1;
						tmp.push_back(make_pair(i, j));
						for (int idx = 0; idx < 4; idx++) {
							int tmp_w = j + move_w[idx];
							int tmp_h = i + move_h[idx];
							if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < C && tmp_h < R) {
								tmp.push_back(make_pair(tmp_h, tmp_w));
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (board[i][j] == '.') {
					board[i][j] = 'O';
					tmpB[i][j] = 0;
				}
			}
		}
		
		if (tmp.size() > 0) {
			for (int i = 0; i < tmp.size(); i++) {
				board[tmp[i].first][tmp[i].second] = '.';
				tmpB[tmp[i].first][tmp[i].second] = -1;
			}
		}

		cnt++;
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}
