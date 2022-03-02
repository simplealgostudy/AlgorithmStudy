#include <bits/stdc++.h>
using namespace std;
int main() {
    long long ans = 0;
    int n, t; 
    scanf("%d%d", &n, &t);
    for (int i = 1; i < n; i++) {
        int a; scanf("%d", &a);
        ans += max(t, a);
        t = a;
    }
    printf("%lld", ans);
    return 0;
}
