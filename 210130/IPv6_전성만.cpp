#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string ou = "0000:0000:0000:0000:0000:0000:0000:0000";
	string str; cin >> str;
	int chk = str.size() - 1;
	int p[8] = {-1};
	for (int i = 1; i < 8; i++) p[i] = p[i-1] + 5;
	int ch = 4, p_point = 7;
	for (int tmp = 0; tmp < 2; tmp++) {
		ch = 4;
		for (int i = chk; i >= 0; --i) {
			ch--;
			if (str[i] == ':' || i == 0) {
				int r = 1;
				if (i > 0 && str[i-1] == ':') { 
					if (i == 1) {
						for (int j = ch+1; j < 4; j++) {
							ou[p[p_point]+1+j] = str[i+r];
							r++;
						}
						cout << ou;
						return 0;
					}
					for (int j = ch+1; j < 4; j++) {
						ou[p[p_point]+1+j] = str[i+r];
						r++;
					}
					chk = i - 2;
					break;
				}
				if (i == 0){
					p_point = 0;
					ch--;
					i--;
				}
				for (int j = ch+1; j < 4; j++) {
					ou[p[p_point]+1+j] = str[i+r];
					r++;
				}
				p_point--;
				ch = 4;
			}
			if (i == -1) { 
				cout << ou;
				return 0;
			}
		}
		int cnt = 0;
		chk++;
		for (int i = 0; i < chk; i++) {
			if (str[i] == ':') cnt++;
		}
		if(cnt != 0) {
			p_point = cnt;
			p_point++;
		}
	}
	cout << ou;
	return 0;
}
