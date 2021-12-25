#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int N = 0;
vector<int> v;
int ansArr[9];
bool visit[9];
int answer = 0;

void dfs(int idx) {
	if (idx == N) {
		
		int tmp = 0;
		
		for (int i = 0; i < N - 1; i++) {
			tmp += abs(ansArr[i] - ansArr[i + 1]);
		}

		answer = max(tmp, answer);

		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			ansArr[idx] = v[i];
			dfs(idx + 1);
			visit[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int a = 0;
		cin >> a;

		v.push_back(a);
	}

	dfs(0);

	cout << answer;
}
