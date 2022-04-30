#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int g[100001];

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int N = 0, a = 0, b = 0;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		g[a]++;
		g[b]++;
	}

	int q = 0, t = 0, k = 0;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> t >> k;

		if (t == 2) cout << "yes" << '\n';
		else {
			if (g[k] > 1) cout << "yes" << '\n';
			else cout << "no" << '\n';
		}
	}
	
}
