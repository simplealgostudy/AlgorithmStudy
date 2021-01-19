#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int max = 0, min = 1000001;
	int n = 0;
	cin >> n;
	vector<int> maxDp(3);
	vector<int> minDp(3);

	int num1 = 0, num2 = 0, num3 = 0;
	cin >> num1 >> num2 >> num3;
	maxDp[0] = num1;
	maxDp[1] = num2;
	maxDp[2] = num3;

	minDp[0] = num1;
	minDp[1] = num2;
	minDp[2] = num3;
	for (int i = 1; i < n; i++) {
		int maxOld1 = maxDp[0], maxOld2 = maxDp[1], maxOld3 = maxDp[2];
		int minOld1 = minDp[0], minOld2 = minDp[1], minOld3 = minDp[2];
		cin >> num1 >> num2 >> num3;

		maxDp[0] += num1;
		maxDp[1] += num2;
		maxDp[2] += num3;

		minDp[0] += num1;
		minDp[1] += num2;
		minDp[2] += num3;

		if (maxOld1 + num1 > maxDp[0]) maxDp[0] = maxOld1 + num1;
		if (maxOld1 + num2 > maxDp[1]) maxDp[1] = maxOld1 + num2;
		if (minOld1 + num1 < minDp[0]) minDp[0] = minOld1 + num1;
		if (minOld1 + num2 < minDp[1]) minDp[1] = minOld1 + num2;

		if (maxOld2 + num1 > maxDp[0]) maxDp[0] = maxOld2 + num1;
		if (maxOld2 + num2 > maxDp[1]) maxDp[1] = maxOld2 + num2;
		if (maxOld2 + num3 > maxDp[2]) maxDp[2] = maxOld2 + num3;
		if (minOld2 + num1 < minDp[0]) minDp[0] = minOld2 + num1;
		if (minOld2 + num2 < minDp[1]) minDp[1] = minOld2 + num2;
		if (minOld2 + num3 < minDp[2]) minDp[2] = minOld2 + num3;

		if (maxOld3 + num2 > maxDp[1]) maxDp[1] = maxOld3 + num2;
		if (maxOld3 + num3 > maxDp[2]) maxDp[2] = maxOld3 + num3;
		if (minOld3 + num2 < minDp[1]) minDp[1] = minOld3 + num2;
		if (minOld3 + num3 < minDp[2]) minDp[2] = minOld3 + num3;
	}

	for (int i = 0; i < 3; i++) {
		if (max < maxDp[i]) max = maxDp[i];
		if (min > minDp[i]) min = minDp[i];
	}
	
	cout << max << " " << min;
}
