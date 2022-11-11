#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int cnt[4001];
bool g[4001][4001];
int answer = 1e9;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		
	int N = 0, M = 0;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int p1 = 0, p2 = 0;
		cin >> p1 >> p2;

		cnt[p1]++;
		cnt[p2]++;
		g[p1][p2] = true;
		g[p2][p1] = true;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (g[i][j]) {
				for (int k = j + 1; k <= N; k++) {
					if (g[i][k] && g[j][k]) {
						answer = min(answer, (cnt[i] + cnt[j] + cnt[k] - 6));
					}
				}
			}
		}
	}

	if (answer == 1e9) cout << -1;
	else cout << answer;

}
