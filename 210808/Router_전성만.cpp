#include <bits/stdc++.h>
using namespace std;
int main() {
    queue<int> q;
    int t; cin >> t;
    while(1) {
        int n; cin >> n;
        if (n == -1) {
            if (q.empty()) {
                cout << "empty";
            } else {
                for (int i = 0; i < t && !q.empty(); i++) {
                    cout << q.front() << ' ';
                    q.pop();
                }
            }
            return 0;
        } else if (n == 0) {
            q.pop();
        } else if (q.size() < t){
            q.push(n);
        }
    }
    return 0;
}