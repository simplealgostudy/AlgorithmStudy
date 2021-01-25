#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int D = 31;
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n; cin >> n;
	while(n--) {
		string A, W, S; // A - Alphabet, W - Plaintext Word, S - Encrypted Text
		cin >> A >> W >> S;
		map<char, int> m;
		char A_chr[A.size()];
		for (int i = 0; i < A.size(); i++) {
			m[A[i]] = i;
			A_chr[i] = A[i];
		}
		vector<int> word(W.size());
		for (int i = 0; i < W.size(); i++) {
			word[i] = m.find(W[i])->second;
		}
		vector<int> res;
		int s_size = S.size();
		int w_size = W.size();
		for (int i = 0; i < A.size(); i++) {
			string str = "";
			for (int j = 0; j < W.size(); j++) {
				str += A_chr[(word[j] + i) % A.size()];
			}
			int cnt = 0;
			long h = 1;
			long wHash = 0, nowHash = 0;
			for (int j = 0; j < w_size; j++) {
				wHash = (wHash * D + str[j]) % MOD;
				nowHash = (nowHash * D + S[j]) % MOD;
				if (j != 0) h = (h * D) % MOD;
			}
			for (int j = 0; j <= s_size - w_size; j++) {
				if (nowHash == wHash) cnt++;
				nowHash = (D * (nowHash - S[j] * h) + S[j + w_size]) % MOD;
				if(nowHash < 0) nowHash += MOD;
			}
			if (cnt == 1) res.push_back(i);
		}
		if (res.size() == 0) {
			cout << "no solution\n";
		} else if (res.size() == 1) {
			cout << "unique: " << res[0] << '\n';
		} else {
			cout << "ambiguous: ";
			for (auto v_res : res) {
				cout << v_res << ' ';
			}
			cout << '\n';
		}
	}	
	return 0;
}
