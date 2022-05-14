#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N = 0;
int W[11][11];
bool visit[11];
int answer = 9e6 + 1;
int start = 0;

void tsp(int node, int cost, int cnt) {
	if (cnt == N - 1) {
		if (W[node][start] != 0) {
			answer = min(answer, cost + W[node][start]);
			return;
		}
	}

	for (int i = 0; i < N; i++) {
		if (W[node][i] != 0 && !visit[i]) {
			visit[i] = true;
			tsp(i, cost + W[node][i], cnt + 1);
			visit[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		start = i;
		visit[i] = true;
		tsp(i, 0, 0);
		visit[i] = false;
	}

	cout << answer;
}
