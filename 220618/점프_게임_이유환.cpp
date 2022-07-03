#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N = 0, k = 0;
string line[2];
bool visit[2][100001];
int answer = 0;
int banTop = -1;


void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	visit[0][0] = true;

	while (!q.empty()) {
		for (int i = 0; i < q.size(); i++) {
			int node = q.front().first;
			int change = q.front().second;
			q.pop();

			int limit = banTop + 1;

			if (node - 1 > limit && !visit[change][node - 1] && line[change][node - 1] == '1') {
				visit[change][node - 1] = true;
				q.push(make_pair(node - 1, change));
			}

			if (node + 1 > limit && !visit[change][node + 1] && line[change][node + 1] == '1') {
				visit[change][node + 1] = true;
				q.push(make_pair(node + 1, change));
			}

			if (node + k >= N) {
				answer = 1;
				break;
			}

			if (node + k < N && !visit[1 - change][node + k] && line[1 - change][node + k] == '1') {
				visit[1 - change][node + k] = true;
				q.push(make_pair(node + k, 1 - change));
			}
		
		}
		banTop += 1;
		if (answer) break;
	}


}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> N >> k;
	cin >> line[0] >> line[1];

	bfs();

	cout << answer;
}
