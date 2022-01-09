#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 0;
double E = 0, W = 0, S = 0, N = 0;
double answer = 0;
vector<double> v;

bool visit[31][31];

int move_w[4] = { 0, 0, 1, -1 };
int move_h[4] = { 1, -1, 0, 0 };

void dfs(int h, int w, int idx, double tmp) {
	if (idx == n) {
		answer += tmp;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int tmp_w = w + move_w[i];
		int tmp_h = h + move_h[i];

		if (!visit[tmp_h][tmp_w]) {
			visit[tmp_h][tmp_w] = true;
			dfs(tmp_h, tmp_w, idx + 1, tmp * v[i]);
			visit[tmp_h][tmp_w] = false;
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> E >> W >> S >> N;

	v.push_back(E / 100);
	v.push_back(W / 100);
	v.push_back(S / 100);
	v.push_back(N / 100);
	
	visit[15][15] = true;
	dfs(15, 15, 0, 1);

	cout.precision(11);
	cout.fixed;
	cout << answer;
}
