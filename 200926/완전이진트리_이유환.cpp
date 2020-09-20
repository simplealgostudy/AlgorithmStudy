#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{	
	vector<int> v;
	vector<int> answer;
	int k = 0;
	cin >> k;

	int size = pow(2, k) - 1;

	for (int i = 0; i < size; i++) {
		int a = 0;
		cin >> a;
		v.push_back(a);
	}

	int i = i = size / 2;
	answer.push_back(v[i]);
	i /= 2;
	int old_i = i;
	k--;

	while (answer.size() != size) {
		if (i > size) {
			i = old_i / 2;
			k--;
			old_i = i;
		}
		answer.push_back(v[i]);
		i += pow(2, k);	
	}

	int line = 1;
	int count = 0;
	cout << answer[0] << endl;
	for (int i = 1; i < size; i++) {
		cout << answer[i] << " ";
		count++;
		if (count == pow(2, line)) {
			cout << endl;
			line++;
			count = 0;
		}
	}
}
