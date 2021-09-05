#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, tmp_max = 0; 
    scanf("%d", &n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    for (int i = 0; i < n; ++i) {
        int a, b; 
        scanf("%d%d", &a, &b);
        pq.emplace(a, b);
    }
    vector<int> v;
    while(!pq.empty()) {
        v.emplace_back(pq.top().second);
        pq.pop();
    }
    vector<int> lis(n, 0);
    int len = 1;
    lis[0] = v[0];
    for (int i = 1; i < v.size(); ++i) {
        auto b = lis.begin();
        auto e = lis.begin() + len;
        auto it = lower_bound(b, e, v[i]);
        if (it == lis.begin() + len) {
            lis[len++] = v[i];
        } else {
            *it = v[i];
        }
    }
    printf("%d", n-len);
    return 0;    
}