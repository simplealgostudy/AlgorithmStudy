#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;


int node[100001];

int dfs(int edge, int cnt) {
	if (node[edge] == -1) return cnt;
	return dfs(node[edge], cnt + 1);
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		
	int n = 0, k = 0;

	cin >> n >> k;

	for (int i = 0; i < n - 1; i++) {
		int p = 0, c = 0;

		cin >> p >> c;

		node[c] = p;
	}

	node[0] = -1;
	int values[100001];

	int target = 0;
	for (int i = 0; i < n; i++) {
		cin >> values[i];

		if (values[i] == k) target = i;
	}


	int answer = dfs(target, 0);

	cout << answer;

}
