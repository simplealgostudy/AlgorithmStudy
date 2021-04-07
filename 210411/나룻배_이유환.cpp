#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int M = 0, t = 0, N = 0;
	
	cin >> M >> t >> N;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> lq;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rq;
	for (int i = 0; i < N; i++) {
		int m = 0;
		string port = "";

		cin >> m >> port;
		if (port == "left") lq.push(make_pair(m, i));
		else rq.push(make_pair(m, i));
	}

	vector<int> answer(N);
	int count = 0;
	char loc = 'l';
	while (!lq.empty() || !rq.empty()) {
		if (!lq.empty() && loc == 'l' && count >= lq.top().first) {
			int idx = 0;
			int oldCount = count;
			count += t;
			while (idx < M) {
				if (lq.empty()) break;
				if (oldCount < lq.top().first) break;
				answer[lq.top().second] = count;
				lq.pop();
				idx++;
			}
						
			loc = 'r';
		}
		else if(!rq.empty() && loc == 'r' && count >= rq.top().first){
			int idx = 0;
			int oldCount = count;
			count += t;
			while (idx < M) {
				if (rq.empty()) break;
				if (oldCount < rq.top().first) break;
				answer[rq.top().second] = count;
				rq.pop();
				idx++;
			}

			loc = 'l';
		}
		else {
			if (!lq.empty() && loc == 'l' && count >= lq.top().first) {}
			else if (!rq.empty() && loc == 'r' && count >= rq.top().first) {}
			else if (!lq.empty() && loc == 'r' && count >= lq.top().first) {
				count += t;
				loc = 'l';
			}
			else if (!rq.empty() && loc == 'l' && count >= rq.top().first) {
				count += t;
				loc = 'r';
			}
			else count++;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << answer[i] << endl;
	}
}
