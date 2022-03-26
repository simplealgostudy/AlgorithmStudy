#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int K = 0, N = 0;
	cin >> K >> N;

	vector<long long> v;
	map<long long, bool> visit;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < K; i++) {
		int k = 0;
		cin >> k;
		v.push_back(k);		
	}

	pq.push(1);
	visit[1] = true;

	long long maxVal = 0;
	for (int i = 0; i < N; i++) {
		long long cur = pq.top();
		pq.pop();
		
		for (int j = 0; j < v.size(); j++) {
			long long tmp = cur * v[j];
			if (!visit[tmp]) {
				if (pq.size() >= N && maxVal <= tmp) break;
				pq.push(tmp);
				visit[tmp] = true;
				maxVal = max(maxVal, tmp);
			}
		}
	}

	cout << pq.top();

}
