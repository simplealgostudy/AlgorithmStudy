#include <iostream>
#include <vector>
#include <queue>
#include<cstring>
#include <algorithm>
using namespace std;
vector<int> v[10001];
bool visit[10001];
int N = 0, M = 0;
int cnt = 0;
void dfs(int idx) {
	cnt++;
	visit[idx] = true;
	for (int i = 0; i < v[idx].size(); i++) {
		if (!visit[v[idx][i]]) dfs(v[idx][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int e1 = 0, e2 = 0;

		cin >> e1 >> e2;

		v[e2].push_back(e1);
	}

	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= N; i++) {
		dfs(i);	
		pq.push(make_pair(cnt, i));

		memset(visit, false, sizeof(visit));
		cnt = 0;	
	}

	vector<int> answer;
	int tmp = pq.top().first;
	answer.push_back(pq.top().second);
	pq.pop();

	while (!pq.empty()) {
		if (tmp > pq.top().first) break;
		else answer.push_back(pq.top().second);

		pq.pop();
	}

	for (int i = answer.size() - 1; i >= 0 ; i--) {
		cout << answer[i] << ' ';
	}
}
