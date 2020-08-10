#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	vector<int> num;

	int a = 0;
	int p = 0;
	int sum = 0;
	bool sw = 0;
	int del_idx = 0;
	int answer = 0;

	cin >> a;
	cin >> p;

	num.push_back(a);

	while(1) {
		while (a != 0) {
			sum += pow((a % 10), p);
			a /= 10;
		}
		a = sum;
		for (int i = 0; i < num.size(); i++) {
			if (sum == num[i]) {
				sw = 1;
				del_idx = i;
				break;		
			}
		}
		if (sw == 1) {
			break;
		}
		num.push_back(sum);
		sum = 0;
	}

	for (int i = 0; i < del_idx; i++) {
		answer++;
	}

	cout << answer << endl;
}
