#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A = 0, B = 0, C= 0;
bool visit[201][201];
bool answer[201];

void dfs(int a, int b, int c) {
	if (visit[a][b]) return;
	if (a == 0) answer[c] = true;

	visit[a][b] = true;

	if (a + b > A) dfs(A, a + b - A, c);
	else dfs(a + b, 0, c);
	if (a + c > A) dfs(A, b, a + c - A);
	else dfs(a + c, b, 0);

	if (a + b > B) dfs(a + b - B, B, c);
	else dfs(0, a + b, c);
	if (b + c > B) dfs(a, B, b + c - B);
	else dfs(a, b + c, 0);

	if (b + c > C) dfs(a, b + c - C, C);
	else dfs(a, 0, b + c);
	if (a + c > C) dfs(a + c - C, b, C);
	else dfs(0, b, a + c);
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> A >> B >> C;
	dfs(0, 0, C);

	for (int i = 0; i < 201; i++) {
		if (answer[i]) cout << i << " ";
	}
}
