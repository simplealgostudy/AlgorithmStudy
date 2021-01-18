#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<double> v;
	
	for (int i = 0; i < n; i++) {
		double tmp = 0;
		cin >> tmp;
		v.push_back(tmp);
	}

	double answer = v[0];
	for (int i = 0; i < n; i++) {
		double sum = 1;
		for (int j = i; j < n; j++) {
			sum *= v[j];
			if (answer < sum) {
				answer = sum;
			}
		}
	}

	cout << fixed;
	cout.precision(3);
	cout << round(answer * 1000) / 1000.0;
}
