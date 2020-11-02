#include <iostream>
using namespace std;

int move_x[4] = { 0, 0, -1, 1 };
int move_y[4] = { -1, 1, 0, 0 };

void dfs(int idx1, int idx2, char check, char(*rgb)[101])
{
	if (rgb[idx1][idx2] != '0') {
		rgb[idx1][idx2] = '0';

		for (int i = 0; i < 4; ++i) {
			int x = idx1 + move_x[i];
			int y = idx2 + move_y[i];
			if (rgb[x][y] == check && x >= 0 && y >= 0) {
				dfs(x, y, check, rgb);
			}
		}
	}
}

int main()
{
	int N;	
	cin >> N;

	char rgb[101][101];
	char rgb2[101][101]; // 색맹
	char tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			rgb[i][j] = tmp;
			
			if (tmp == 'G') {
				rgb2[i][j] = 'R';
			}
			else {
				rgb2[i][j] = tmp;
			}
		}
	}


	int answer = 0;
	int answer2 = 0;
	char check;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (rgb[i][j] != '0') {
				check = rgb[i][j];
				dfs(i, j, check, rgb);
				answer++;
			}

			if (rgb2[i][j] != '0') {
				check = rgb2[i][j];
				dfs(i, j, check, rgb2);
				answer2++;
			}
		}
	}

	cout << answer << " " << answer2;
}
