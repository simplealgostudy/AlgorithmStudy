#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n; cin >> n;
	double d[n];
	double res[n];
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		res[i] = d[i];
		for (int j = 0; j < i; j++) {
			d[j] *= d[i];
			if (res[i] < d[j]) res[i] = d[j];
		}
	}
	double MAX = res[0];
	for (int i = 1; i < n; i++) MAX = res[i] > MAX ? res[i] : MAX;
	cout << fixed;
	cout.precision(3);
	cout << round(MAX * 1000) / 1000.0;
	return 0;
}
