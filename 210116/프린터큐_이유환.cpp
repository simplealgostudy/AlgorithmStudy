#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{		
	vector<int> answer;	
	int t = 0;
	cin >> t;

	for (int t_i = 0; t_i < t; t_i++) {
		queue<pair<int, int>> q;
		vector<pair<int, int>> v;

		int n = 0, m = 0;
		cin >> n >> m;

		int max = 0;
		int max_idx = 0;
		for (int i = 0; i < n; i++) {
			int weight = 0;
			cin >> weight;
			v.push_back(make_pair(weight, i));

			if (max < weight) {
				max = weight;
				max_idx = i;
			}
		}

		q.push(make_pair(max, max_idx));
		v[max_idx].first = 0;
		
		while (q.size() != n) {
			int idx = max_idx;
			int count = 0;
			max = 0;
			while (count != n) {				
				if (max < v[idx].first) {
					max = v[idx].first;
					max_idx = v[idx].second;
				}

				idx = (idx + 1) % n;
				count++;
			}

			q.push(make_pair(max, max_idx));
			v[max_idx].first = 0;
		}	
		
		for (int i = 0; i < n; i++) {
			if (m == q.front().second) {
				answer.push_back(i + 1);
				break;
			}
			q.pop();
		}

	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}
