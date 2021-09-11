#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n = 0;

	cin >> n;

	vector<pair<int, int>> v;
	int dp[101];

	v.push_back(make_pair(0, 0));
	for (int i = 0; i < n; i++) {
		int n1 = 0, n2 = 0;

		cin >> n1 >> n2;
		v.push_back(make_pair(n1, n2));
	}

	sort(v.begin(), v.end());

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (v[i].second > v[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		answer = max(answer, dp[i]);
	}

	cout << n - answer;
}
