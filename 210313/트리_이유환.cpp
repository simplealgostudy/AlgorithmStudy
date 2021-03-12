#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> slice(const vector<int>& v, int a, int b) {
	// a ~ b까지의 인덱스 반환
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostorder(const vector<int>& preorder, const vector<int>& inorder) {
	int vsize = preorder.size();
	if (preorder.empty()) return;
	int root = preorder[0];
	int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	int R = vsize - 1 - L;
	printPostorder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	printPostorder(slice(preorder, L + 1, vsize), slice(inorder, L + 1, vsize));
	cout << root << " ";
	return;
}

int main()
{
	int T = 0;
	cin >> T;

	for (int testCase = 0; testCase < T; testCase++) {
		int n = 0;
		cin >> n;

		vector<int> preorder;
		vector<int> inorder;
		for (int i = 0; i < n; i++) {
			int tmp = 0;
			cin >> tmp;

			preorder.push_back(tmp);
		}
		for (int i = 0; i < n; i++) {
			int tmp = 0;
			cin >> tmp;

			inorder.push_back(tmp);
		}

		printPostorder(preorder, inorder);
		cout << endl;
	}
}
