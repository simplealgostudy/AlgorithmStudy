#include <bits/stdc++.h>
using namespace std;
int n, s, m;
int main() {
    scanf("%d%d%d", &n, &s, &m);
    set<int> st; st.insert(s);
    for (int i = 0; i < n; i++) {
        set<int> next = st;
        st.clear();
        int l; 
        scanf("%d", &l);
        for (auto it : next) {
            if (it - l >= 0) st.insert(it - l);
            if (it + l <= m) st.insert(it + l);
        }
        if (st.empty()) {
            printf("-1");
            return 0;
        }
    }
    auto it = st.end();
    it--;
    printf("%d",*it);
    return 0;
}
