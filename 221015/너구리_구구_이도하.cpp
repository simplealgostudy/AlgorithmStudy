#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<long long>> v;
vector<bool> visit(5001);

void bfs() {

	queue<pair<int, long long>> q;

	q.push(make_pair(1, 0));
	visit[1] = true;
	while (!q.empty()) {	
		int node = q.front().first;
		long long cnt = q.front().second;
		q.pop();
		
		visit[node] = true;
		for (int i = 0; i < v[node].size(); i++) {
			if (v[node][i] > 0 && !visit[i]) {
				v[node][i] += cnt;
				q.push(make_pair(i, v[node][i]));				
			}		
		}	
	}

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int N = 0;
	cin >> N;
	
	for (int i = 0; i < N + 1; i++) {
		vector<long long> tmp(N + 1);
		v.push_back(tmp);
	}

	for (int i = 0; i < N - 1; i++) {
		int a, b = 0;
		cin >> a >> b;

		long long c = 0;
		cin >> c;

		v[a][b] = c;
		v[b][a] = c;
	}

	bfs();

	long long answer = 0;
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N + 1; j++) {
			if (answer < v[i][j]) answer = v[i][j];
		}
	}
	cout << answer;

}
