#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n = 0;
int move_w[4] = { 0, 0, -1, 1};
int move_h[4] = { -1, 1, 0, 0};
int answer = 0;
vector<vector<int>> v;
int startH = 0, startW = 0;
bool fishSw = true;
int sharkSize = 2;
int sharkIn = 0;

void bfs(int h, int w) {
	fishSw = false;
	int time = 0;
	int check[21][21] = { 0 };
	bool visit[21][21] = { false };

	visit[h][w] = true;

	vector<pair<int, int>> fishV;
	vector<int> fishDisp;
	queue<pair<int, int>> q;
	q.push(make_pair(h, w));

	while (!q.empty()) {
		int h = q.front().first;
		int w = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tmp_w = w + move_w[i];
			int tmp_h = h + move_h[i];
			if (tmp_w >= 0 && tmp_h >= 0 && tmp_w < n && tmp_h < n) {
				if (v[tmp_h][tmp_w] == 0 || v[tmp_h][tmp_w] <= sharkSize) {
					if (visit[tmp_h][tmp_w] == false && check[tmp_h][tmp_w] == 0) {
						check[tmp_h][tmp_w] = check[h][w] + 1;
						visit[tmp_h][tmp_w] = true;
						q.push(make_pair(tmp_h, tmp_w));
						if (v[tmp_h][tmp_w] != 0 && v[tmp_h][tmp_w] < sharkSize) {				
							fishV.push_back(make_pair(tmp_h, tmp_w));	
							fishDisp.push_back(check[tmp_h][tmp_w]);
						}
					}
				}				
			}
		}

		if (fishSw == true) break;
	}

	if (!fishV.empty()) {
		int minH = fishV[0].first;
		int minW = fishV[0].second;
		int minDistance = fishDisp[0];
		for (int i = 1; i < fishV.size(); i++) {
			if (minDistance >= fishDisp[i]) {
				if (minH > fishV[i].first) {
					minH = fishV[i].first;
					minW = fishV[i].second;
				}
				else if (minH == fishV[i].first) {
					if (minW > fishV[i].second) {
						minH = fishV[i].first;
						minW = fishV[i].second;
					}
				}
			}		
		}

		v[minH][minW] = 0;
		answer += check[minH][minW];
		fishSw = true;
		startH = minH;
		startW = minW;

		sharkIn++;
		if (sharkIn == sharkSize) {
			sharkSize++;
			sharkIn = 0;
		}
	}	
}

int main()
{
	cin >> n;

	
	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		for (int j = 0; j < n; j++) {
			int fish = 0;
			cin >> fish;
			if (fish == 9) {
				startH = i;
				startW = j;
				tmp.push_back(0);
			}
			else tmp.push_back(fish);
		}
		v.push_back(tmp);
	}

	while (fishSw) {
		bfs(startH, startW);
	}

	cout << answer;
}
