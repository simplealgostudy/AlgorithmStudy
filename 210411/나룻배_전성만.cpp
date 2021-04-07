// 참고 : http://acm.student.cs.uwaterloo.ca/~acm00/050917/data/B.c
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long m, t, n; cin >> m >> t >> n;
    vector<long> arr(20001, 0), res(20001, 0);
    vector<string> dic(20001, "");
    for (int i = 0; i < n; i++) cin >> arr[i] >> dic[i];
    arr[n] = 99999999;
    long nl, nr, cnt;
    for (nl = 0; nl < n && dic[nl][0] != 'l'; nl++);
    for (nr = 0; nr < n && dic[nr][0] != 'r'; nr++);
    for (cnt = 0; nl < n || nr < n;) {
        long tmp = min(arr[nl], arr[nr]);
        if (cnt < tmp) cnt = tmp;
        for (int i = 0; i < m && arr[nl] <= cnt; i++) {
            res[nl] = cnt + t;
            for (; ++nl < n && dic[nl][0] != 'l';);
        }
        cnt += t;
        tmp = min(arr[nl], arr[nr]);
        if (cnt < tmp) cnt = tmp;
        for (int i = 0; i < m && arr[nr] <= cnt; i++) {
            res[nr] = cnt + t;
            for (; ++ nr < n && dic[nr][0] != 'r';);
        }
        cnt += t;
    }
    for (int i = 0; i < n; i++) cout << res[i] << '\n';
    return 0;
}
