#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N = 0, M = 0;
int answer = 0;
vector<bool> visit(101);
vector<pair<int, int>> board(101);

void bfs() {
	bool sw = false;
	queue<int> q;	
	q.push(1);
	visit[1] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for (int i = 1; i <= 6; i++) {
			int move = cur + i;
				
			if (move == 100) {
				answer = board[cur].first + 1;	
				sw = true;
				break;
			}

			if (board[move].second > 0) {
				move = board[move].second;
			}

			if (!visit[move] && move <= 100) {		
				visit[move] = true;
				board[move].first = board[cur].first + 1;
				q.push(move);
			}		
		}

		if (sw) break;
	}

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		board[x] = make_pair(0, y);
	}

	bfs();
	cout << answer;
}
