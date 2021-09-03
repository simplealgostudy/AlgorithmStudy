#include <iostream>
#include <vector>
using namespace std;

int S[9], W[9];
int N = 0, answer = 0;

void dfs(int idx) {
	if (idx == N) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (S[i] <= 0) cnt++;
		}

		if (answer < cnt) answer = cnt;
		return;
	}

	if (S[idx] <= 0) dfs(idx + 1);
	else {
		bool sw = false;
		for (int i = 0; i < N; i++) {
			if (!(idx == i || S[i] <= 0)) {
				sw = true;
				S[idx] -= W[i];
				S[i] -= W[idx];
				dfs(idx + 1);
				S[idx] += W[i];
				S[i] += W[idx];
			}
		}

		if (!sw) dfs(idx + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		int s = 0, w = 0;
		cin >> s >> w;

		S[i] = s;
		W[i] = w;
	}

	dfs(0);

	cout << answer;
}
