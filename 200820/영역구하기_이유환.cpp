#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer_tmp = 0;
int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };

void dfs(vector < vector <int> >& rect, int x, int y, int x_size, int y_size) {
	if (rect[y][x] == 0) {
		rect[y][x] = 1;
		answer_tmp++;
		for (int i = 0; i < 4; i++) {
			int m_x = move_x[i] + x;
			int m_y = move_y[i] + y;
			if (m_x >= 0 && m_y >= 0 && m_x < x_size && m_y < y_size) {
				dfs(rect , m_x, m_y, x_size, y_size);
			}
		}
	}
}

int main() {
	int x = 0;
	int y = 0;
	int rect_num = 0;
	vector<int> answer;
	
	cin >> y;
	cin >> x;
	cin >> rect_num;
    
	vector<vector<int>> rect;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			vector<int> rect_v;
			rect_v.resize(x);
			rect.push_back(rect_v);
		}
	}

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			rect[i][j] = 0;
		}
	}

	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	int old_y = 0;

	for (int i = 0; i < rect_num; i++) {
		cin >> x1;
		cin >> y1;
		cin >> x2;
		cin >> y2;

		old_y = y2 - y1;
		y1 = y - y2;
		y2 = y1 + old_y;

		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				rect[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (rect[i][j] == 0) {
				answer_tmp = 0;
				dfs(rect, j, i, x, y);
				answer.push_back(answer_tmp);
			}		
		}	
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	
	for (int i = 0; i < rect.size(); i++) {
		rect[i].clear(); 
	} 
	rect.clear();
}
