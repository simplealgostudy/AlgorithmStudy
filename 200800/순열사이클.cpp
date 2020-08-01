#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testCase = 0;
	cin >> testCase;

	vector<int> array;
	vector<int> answer;

	for (int t = 0; t < testCase; t++) {
		
		int size = 0;
		cin >> size;
		
		for (int i = 0; i < size; i++) {
			int value = 0;
			cin >> value;
			array.push_back(value);
		}

		int idx = 0;
		int old_idx = 0;
		int count = 0;
		int answer_tmp = 0;

		for (int i = 0; i < array.size(); i++) {
			idx = i;
			old_idx = idx;
			while (1) {
				if (array[old_idx] == -1 && count > 0) {
					answer_tmp++;
					break;
				}
				else if (array[old_idx] == -1 && count == 0) {
					break;
				}
				else {
					idx = array[idx] - 1;
					array[old_idx] = -1;
					old_idx = idx;
					count++;
				}
			}		
			count = 0;
		}
		answer.push_back(answer_tmp);
		array.clear();
	}
	
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}