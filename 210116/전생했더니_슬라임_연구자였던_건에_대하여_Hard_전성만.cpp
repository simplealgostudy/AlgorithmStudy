#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t;
	for (cin >> t; t--;) {
		int n; cin >> n;
		long long ans = 1;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for (int i = 0; i < n; i++) {
			long long p; cin >> p;
			pq.push(p);
		}
		while(!pq.empty() && pq.size() > 1) {
			long long tmp = pq.top();
			pq.pop();
			if(!pq.empty()) tmp *= pq.top(); 
			pq.pop();
			pq.push(tmp);
			ans = (ans * (tmp % MOD)) % MOD;
		}
		cout << ans << '\n';
	}
	return 0;
}
