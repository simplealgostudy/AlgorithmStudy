#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int N = 0, H = 0, T = 0;
	cin >> N >> H >> T;

	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		int h = 0;
		cin >> h;

		pq.push(h);
	}

	int check = 0;
	for (int i = 1; i <= T; i++) {
		int h = pq.top();
		pq.pop();

		if (h >= H) check = i;
		if (h > 1) h /= 2;		

		pq.push(h);
	}

	if (pq.top() < H) {
		cout << "YES" << '\n';
		cout << check;
	}
	else {
		cout << "NO" << '\n';
		cout << pq.top();
	}
}
