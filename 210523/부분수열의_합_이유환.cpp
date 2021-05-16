#include <iostream>
#include <vector>
using namespace std;
vector<int> v(21);
int N = 0;
int S = 0;
int answer = 0;
void dfs(int idx, int sum) {
	sum += v[idx];

	if (idx >= N) return;
	if (sum == S) answer++;
	dfs(idx + 1, sum);
	dfs(idx + 1, sum - v[idx]);
}

int main()
{	
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);	
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int num = 0;
		cin >> num;
		v[i] = num;
	}

	dfs(0, 0);

	cout << answer;
}
