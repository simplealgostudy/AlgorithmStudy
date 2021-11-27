#include <bits/stdc++.h>
using namespace std;
class node {
public:
    bool chk = 0;
    node* next[26] = {nullptr,};
    node(){}
};
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    node* head[26] = {nullptr, };
    for (int i = 0; i < n; ++i) {
        string str; cin >> str;
        if(head[str[0]-'a'] == nullptr) head[str[0]-'a'] = new node();
        node *cur = head[str[0]-'a'];
        cur->chk = 1;
        for (int j = 1; j < str.size(); ++j) {
            if (cur->next[str[j]-'a'] == nullptr) {
                cur->next[str[j]-'a'] = new node();
            }
            cur = cur->next[str[j]-'a'];
            cur->chk = 1;
        }
    }
    int answer = 0;
    for (int i = 0; i < m; ++i) {
        string str; cin >> str;
        node * cur = head[str[0]-'a'];
        if (cur != nullptr) {
            bool check = 1;
            for (int j = 1; j < str.size(); ++j) {
                if (cur->next[str[j]-'a'] == nullptr) {
                    check = 0;
                    break;
                }
                cur = cur->next[str[j]-'a'];
            }
            if (check) answer++;
        }
    }
    cout << answer;
    return 0;
}
