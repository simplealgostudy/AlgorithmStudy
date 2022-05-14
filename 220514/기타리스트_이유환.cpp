#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int N = 0, S = 0, M = 0;
	cin >> N >> S >> M;

	int v[51];
	int dp[51][1001];

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	memset(dp, 0, sizeof(dp));

	dp[0][S] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j] == 1) {

				if ((j + v[i]) <= M) {
					dp[i][j + v[i]] = 1;
				}

				if ((j - v[i]) >= 0) {
					dp[i][j - v[i]] = 1;
				}
		
			}
		}
	}

	int answer = -1;
	for (int i = M; i >= 0; i--) {
		if (dp[N][i]) {
			answer = i;
			break;
		}
	}

	cout << answer;
}
