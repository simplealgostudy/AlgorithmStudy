#include <iostream>
#include <vector>
using namespace std;
vector<int> g[101];
vector<bool> check(101, false);
int answer = -1;
int n = 0;

void dfs(int idx, int target, int count) {
	if (check[idx] == false) {
		check[idx] = true;

		if (target == idx) {
			answer = count;
			return;
		}

		count++;
		for (int i = 0; i < g[idx].size(); i++) {
			dfs(g[idx][i], target, count);
		}
	}
}

int main()
{
	cin >> n;

	int person1 = 0, person2 = 0;
	cin >> person1 >> person2;

	int m = 0;
	cin >> m;

	for (int i = 1; i <= m; i++) {
		int parent = 0, child = 0;
		cin >> parent >> child;

		g[parent].push_back(child);
		g[child].push_back(parent);
	}

	dfs(person1, person2, 0);
	cout << answer;
}
