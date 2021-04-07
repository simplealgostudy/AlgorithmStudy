#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
	constexpr bool operator() (pair<int, int> const& a, pair<int, int> const& b) const noexcept {
		if (a.first == b.first) return a.second > b.second;
		else return a.first > b.first;
	}
};

int main() {
	int A = 0, B = 0, N = 0;

	cin >> A >> B >> N;
	
	priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
	int bmax = 0, amax = 0;
	for (int i = 0; i < N; i++) {
		int t = 0, m = 0;
		char c = '.';

		cin >> t >> c >> m;

		for (int j = 0; j < m; j++) {
			if (c == 'B') {
				if (bmax >= t) {
					pq.push(make_pair(bmax, 'b'));
					bmax += A;
				}
				else {
					pq.push(make_pair(t, 'b'));
					bmax = t + A;
				}
			}
			else {
				if (amax >= t) {
					pq.push(make_pair(amax, 'r'));
					amax += B;
				}
				else {
					pq.push(make_pair(t, 'r'));
					amax = t + B;
				}
			}
		}
	}

	vector<int> blue;
	vector<int> red;

	int count = 1;
	while (!pq.empty()) {
		int t = pq.top().first;
		char c = pq.top().second;
		pq.pop();
		
		if (c == 'b') {
			blue.push_back(count);
		}
		else {
			red.push_back(count);
		}
		count++;
	}

	cout << blue.size() << endl;
	for (int i = 0; i < blue.size(); i++) {
		cout << blue[i] << " ";
	}
	cout << endl;
	cout << red.size() << endl;
	for (int i = 0; i < red.size(); i++) {
		cout << red[i] << " ";
	}
}
