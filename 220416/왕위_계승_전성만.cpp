#include <bits/stdc++.h>
using namespace std;
map<string, vector<string>> parent;
map<string, double> blood;
double dfs(string str) {
    if (blood[str] != 0 || parent[str].empty()) return blood[str];
    return blood[str] = (dfs(parent[str][0]) + dfs(parent[str][1])) / 2;    
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    string str; cin >> str;
    for (int i = 0; i < n; i++) {
        string s1, s2, s3; cin >> s1 >> s2 >> s3;
        parent[s1].push_back(s2);
        parent[s1].push_back(s3);
    }
    double d = 0;
    string ans = "";
    blood[str] = 1;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;        
        double tmp = dfs(s);
        if (d < tmp) {
            d = tmp;
            ans = s;
        }
    }
    cout << ans;
    return 0;
}