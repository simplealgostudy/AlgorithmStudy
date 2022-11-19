#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		
	int N = 0;
	cin >> N;

	int idx = 0;
	bool sw = false;

	string tmp = "";

	queue<char> way;
	deque<int> value;

	while (idx < N) {
		char c = '.';
		cin >> c;

		if (c == 'S' || c == 'M' || c == 'U' || c == 'P' || c == 'C') {
			
			if(tmp != "") value.push_back(stoi(tmp));		
			tmp = "";

			if (c == 'C') {

				int answer = 0;

				while (!way.empty()) {
					char w = way.front();
					way.pop();

					int v1 = value.front();
					value.pop_front();

					int v2 = value.front();
					value.pop_front();

					if (w == 'S') {
						value.push_front(v1 - v2);
					}
					else if (w == 'M') {
						value.push_front(v1 * v2);
					}
					else if (w == 'U') {
						value.push_front(v1 / v2);
					}
					else if (w == 'P') {
						value.push_front(v1 + v2);
					}

				}

				cout << value.front() << ' ';
				sw = true;
			}
			else {
				way.push(c);
			}

			idx++;
		}
		else {
			tmp += c;
		}		
	}

	if(!sw) cout << "NO OUTPUT";

}
