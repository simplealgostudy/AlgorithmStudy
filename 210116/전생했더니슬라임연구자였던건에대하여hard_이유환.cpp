#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int limit = 1e9 + 7;
int main()
{		
	int t = 0;
	cin >> t;
	
	for (int t_i = 0; t_i < t; t_i++) {		
		priority_queue<long long, vector<long long>, greater<long long> > pq;
		int n = 0;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			long long tmp = 0;
			scanf("%lld", &tmp);

			pq.push(tmp);
		}

		long long answer = 1;
		
		while (pq.size() > 1) {
			long long tmp1 = pq.top();
			pq.pop();
			long long tmp2 = pq.top();
			pq.pop();
			answer = (answer * (tmp1 * tmp2 % limit)) % limit;
			pq.push(tmp1 * tmp2);
		}
		
		printf("%lld\n", answer);
	}
}
