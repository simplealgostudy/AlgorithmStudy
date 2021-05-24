#include <iostream>
#include <vector>
using namespace std;

int main()
{	
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int N = 0, M = 0;
	cin >> N >> M;

	vector<vector<int>> v(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num = 0;
			cin >> num;
			v[i][j] = num;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + v[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << '\n';
	}
}
