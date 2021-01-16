#include <bits/stdc++.h>
using namespace std;
struct th { int x, y, z; };
int main() {
	int n; scanf("%d", &n);
	th cur, min_cur, min_back, max_cur, max_back;
	scanf("%d%d%d", &cur.x, &cur.y, &cur.z);
	min_back = max_back = cur;
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &cur.x, &cur.y, &cur.z);
		min_cur = {cur.x + min(min_back.x, min_back.y), cur.y + min(min_back.x, min(min_back.y, min_back.z)), cur.z + min(min_back.y, min_back.z)};
		max_cur = {cur.x + max(max_back.x, max_back.y), cur.y + max(max_back.x, max(max_back.y, max_back.z)), cur.z + max(max_back.y, max_back.z)};
		min_back = min_cur;
		max_back = max_cur;
	}
	printf("%d %d", max(max_back.x, max(max_back.y, max_back.z)), min(min_back.x, min(min_back.y, min_back.z)));
	return 0;
}
