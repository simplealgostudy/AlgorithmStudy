#include <iostream>
#include <queue>
using namespace std;
bool check[100001];
queue<pair<int, int>> q;

void bfs(int a, int b, int n, int m) {
	while (!q.empty()) {
		int node = q.front().first;
		int answer = q.front().second;

		if (node == m) {
			cout << answer;
			break;
		}

		q.pop();

		int next[8] = {
			node * a,
			node * b,
			node - a,
			node + b,
			node - b,
			node + 1,
			node - 1,
			node + a
		};

		for (int i = 0; i < 8; i++) {
			if (next[i] <= 100000 && next[i] >= 0) {
				if (check[next[i]] != true) {
					check[next[i]] = true;
					q.push(make_pair(next[i], answer + 1));
				}
			}
		}
	}
}

int main()
{
	int a = 0, b = 0;
	int n = 0, m = 0;
	

	cin >> a >> b >> n >> m;

	q.push(make_pair(n, 0));
	check[n] = true;

	bfs(a, b, n, m);
}
