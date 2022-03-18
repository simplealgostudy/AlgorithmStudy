#include <bits/stdc++.h>
using namespace std;

struct per {
    int idx, time;
};

bool comp(pair<int, per> &a, pair<int, per> &b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N, T, W, M; cin >> N >> T >> W;
    queue<per> q;
    for (int i = 0; i < N; i ++) {
        int id, ti; cin >> id >> ti;
        q.push({id, ti});
    }
    cin >> M;
    vector<pair<int, per>> v;
    for (int i = 0; i < M; i ++) {
        int id, ti, cn; cin >> id >> ti >> cn;
        v.push_back({cn, {id, ti}});
    }
    sort(v.begin(), v.end(), comp);
    queue<pair<int, per>> tmpq;
    for (auto i : v) {
        tmpq.push(i);
    }
    int t = 0;
    while(t < W) {
        per cur = q.front();
        q.pop();
        int cnt = cur.time - T;
        while (cur.time > 0 && cur.time > cnt && t < W) {
            cout << cur.idx << '\n';
            cur.time--;
            t++;
        }
        while (!tmpq.empty() && t >= tmpq.front().first) {
            q.push(tmpq.front().second);
            tmpq.pop();
        }
        if (cur.time > 0) {
            q.push({cur.idx, cur.time});
        }
    }
    return 0;
}
