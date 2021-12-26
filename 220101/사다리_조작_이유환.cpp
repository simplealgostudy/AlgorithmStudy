#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int N = 0, M = 0, H = 0;
bool line[32][32];
int answer = 32 * 12;

bool check() {
	for (int i = 1; i <= N; i++) {
		int r = i;
		for (int j = 1; j <= H; j++) {
			if (line[j][r]) r++;
			else if (line[j][r - 1]) r--;
		}

		if (r != i) return false;
	}
	return true;
}

void dfs(int idx, int cnt) {
	if (cnt > 3) return;
	if (check()) {
		answer = min(cnt, answer);
		return;
	}

	for (int i = idx; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			if (!line[i][j] && !line[i][j - 1] && !line[i][j + 1]) {
				line[i][j] = true;
				dfs(i, cnt + 1);
				line[i][j] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> N >> M >> H;
	
	for (int i = 0; i < M; i++) {
		int a = 0, b = 0;
		cin >> a >> b;

		line[a][b] = true;
	}

	dfs(1, 0);

	if(answer > 3) cout << -1;
	else cout << answer;
}
