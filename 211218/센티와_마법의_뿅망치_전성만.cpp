#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, h, t; cin >> n >> h >> t;
    priority_queue<int> pq;
    while(n--) {
        int m; cin >> m;
        pq.push(m);
    }
    for (int i = 0; i < t; ++i) {
        if (pq.top() >= h) {
            if (pq.top() == 1) {
                cout << "NO\n1";
                return 0;
            }
            pq.push(pq.top()/2);
            pq.pop();
        } else {
            cout << "YES\n" << i;
            return 0;
        }
    }
    if (pq.top() >= h) {
        cout << "NO\n" << pq.top();
    } else {
        cout << "YES\n" << t;
    }
    return 0;
}