#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t;
	for (cin >> t;t--;) {
		int n, m; cin >> n >> m;
		queue<pair<int, int>> q;
		map<int, int, greater<int>> mp;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			q.push({x, i});
			if (mp.find(x) != mp.end()) mp.find(x) -> second++;
			else mp[x]=1;
		}
		int cnt = 1;
		while(!q.empty()) {
			pair<int, int> cur = q.front();
			if (mp.begin()->first == cur.first) {
				if (cur.second == m) {
					cout << cnt << '\n';
					break;
				}
				if(mp.begin()->second==1) mp.erase(mp.begin());
				else mp.begin()->second--;
				cnt++;
			} else {
				q.push(cur);
			}
			q.pop();
		}
	}
	return 0;
}