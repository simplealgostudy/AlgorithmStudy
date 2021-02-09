#include <bits/stdc++.h>
using namespace std;
struct th {
	bitset<9> b;
  	int cnt;
  	vector<bool> chk;
};
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int test_case; cin >> test_case;
	while(test_case--) {
		bitset<9> b;
		for (int i = 0; i < 9; i++) {
			char chr; cin >> chr;
			if (chr == '*') b[i] = 1;
		}
    		vector<bool> chk(9, false);
		queue<th> q;
		q.push({b, 0, chk});
		while(!q.empty()) {
			th cur = q.front();
			if (!cur.b.count()) {
				cout << cur.cnt << '\n';
				break;
			}
			q.pop();
			for (int i = 0; i < 9; i++) {
				bitset<9> next = cur.b;
				if (cur.chk[i]) continue;
				next[i].flip();
				if (i - 3 >= 0) next[i-3].flip();
				if (i + 3 < 9) next[i+3].flip();
				if (i % 3 == 0 && i + 1 < 9) next[i+1].flip();
				else if (i % 3 == 1) {
					if (i - 1 >= 0) next[i-1].flip();
					if (i + 1 < 9) next[i+1].flip();
				}
				else if (i % 3 == 2 && i - 1 >= 0) next[i-1].flip();
        			cur.chk[i] = true;
				q.push({next, cur.cnt+1, cur.chk});
        			cur.chk[i] = false;
			}
		}
	}
	return 0;
}
