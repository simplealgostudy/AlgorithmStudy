#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int N = 0, M = 0;
	cin >> N >> M;

	map<string, priority_queue<string, vector<string>, greater<string>>> m;
	map<string, string> mt;
	for (int i = 0; i < N; i++) {
		int n = 0;
		string team;
		cin >> team >> n;
		
		for (int j = 0; j < n; j++) {
			string member;
			cin >> member;

			m[team].push(member);
			mt[member] = team;
		}
	}

	for (int i = 0; i < M; i++) {
		string str;
		int q = 0;
		cin >> str >> q;

		if (q == 0) {
			while (!m[str].empty()) {
				cout << m[str].top() << '\n';
				m[str].pop();
			}
		}
		else {
			cout << mt[str] << '\n';
		}
	}

}
