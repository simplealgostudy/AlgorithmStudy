#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int N = 0, Q = 0;
	cin >> N >> Q;

	map <int, int> m;
	for (int i = 0; i < Q; i++) {
		bool sw = true;
		int q = 0;
		cin >> q;
		int tmp = q;
		int cur = 0;

		while (1) {
			if (sw) {
				if (tmp == 1 && m[tmp] == 0) {
					cout << 0 << '\n';
					m[q] = 1;
					break;
				}
				else if (m[tmp] == 1) {
					sw = false;
				}
				else {
					tmp /= 2;
				}
			}
			else {
				if (m[tmp] == 1) cur = tmp;
				else if (tmp == 1) {
					cout << cur << '\n';
					break;
				}
				tmp /= 2;
			}
			
		}
	}
}
