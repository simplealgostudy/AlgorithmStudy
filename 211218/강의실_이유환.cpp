#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int N = 0;
	cin >> N;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> startPq;
	
	for (int i = 0; i < N; i++) {
		int n = 0, s = 0, e = 0;
		cin >> n >> s >> e;

		startPq.push(make_pair(s, e));
	}

	priority_queue<int, vector<int>, greater<int>> ansPq;
	ansPq.push(startPq.top().second);
	startPq.pop();

	while (!startPq.empty()) {
		int start = startPq.top().first;
		int end = startPq.top().second;
		startPq.pop();

		if (start >= ansPq.top()) {
			ansPq.push(end);
			ansPq.pop();
		}
		else {
			ansPq.push(end);
		}
	}

	cout << ansPq.size();
}
