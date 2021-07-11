#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int answer = -1;
string board = "";
int move_w[4] = { -1, 1, 0, 0 };
int move_h[4] = { 0, 0, 1, -1 };

void bfs() {
	map<string, int> m;
	queue<pair<string, int>> q;
	m[board] = 1;
	q.push(make_pair(board, 0));

	while (!q.empty()) {
		string curB = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if ((answer == -1 || answer > cnt) && curB == "123456780") {
			answer = cnt;
		}
		int idx = curB.find('0');

		int h = idx / 3;
		int w = idx % 3;

		for (int i = 0; i < 4; i++) {
			int tmp_w = w + move_w[i];
			int tmp_h = h + move_h[i];
			if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < 3 && tmp_h < 3) {
				string next = curB;

				swap(next[h * 3 + w], next[tmp_h * 3 + tmp_w]);
				if (m[next] != 1) {
					m[next] = 1;
					q.push(make_pair(next, cnt + 1));
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	for (int i = 0; i < 9; i++) {
		char c = '.';
		cin >> c;
		board += c;
	}

	bfs();
	cout << answer;
}
