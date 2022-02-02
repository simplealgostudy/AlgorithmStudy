#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0, R1 = 0, R2 = 0, answer = 0;
vector<pair<int, int>> v[100001];
bool visit[100001];

void dfs(int idx, int sum, int maxWeight) {
	if (idx == R2) {
		answer = sum - maxWeight;
		return;
	}

	visit[idx] = true;

	for (int i = 0; i < v[idx].size(); i++) {
		if (!visit[v[idx][i].first]) {
			dfs(v[idx][i].first, sum + v[idx][i].second, max(maxWeight, v[idx][i].second));
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

		
	cin >> N >> R1 >> R2;
	
	for (int i = 0; i < N - 1; i++) {
		int e1 = 0, e2 = 0, w = 0;
		cin >> e1 >> e2 >> w;

		v[e1].push_back(make_pair(e2, w));
		v[e2].push_back(make_pair(e1, w));
	}

	dfs(R1, 0, 0);

	cout << answer;
}
