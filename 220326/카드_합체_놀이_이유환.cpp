#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int n = 0, m = 0;

	cin >> n >> m;

	priority_queue<long long, vector<long long>, greater<long long>> q;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;

		q.push(tmp);
	}

	for (int i = 0; i < m; i++) {
		long long x = q.top();
		q.pop();

		long long y = q.top();		
		q.pop();

		q.push(x + y);
		q.push(x + y);
	}

	long long answer = 0;
	while (!q.empty()) {
		answer += q.top();
		q.pop();
	}

	cout << answer;
}
