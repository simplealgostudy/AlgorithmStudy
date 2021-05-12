#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main()
{	
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);	
	int N = 0;
	cin >> N;

	map<int, pair<pair<char, long long>, pair<long long, int>>> m;

	queue<int> q;

	for (int i = 2; i <= N; i++) {
		char t = '.';
		int a = 0, p = 0;
		cin >> t >> a >> p;
		m[i].first.first = t;

		if(t == 'W') m[i].first.second = -a;
		else m[i].first.second = a;
		m[i].second.first = p;
		m[p].second.second++;
	}

	for (int i = 2; i <= N; i++) {
		if (m[i].second.second == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int node = q.front();
		int next = m[node].second.first;
		q.pop();
		
		if (m[node].first.second > 0) m[next].first.second += m[node].first.second;
		m[next].second.second--;

		if (m[next].second.second == 0) q.push(next);
	}

	cout << m[1].first.second;
}
