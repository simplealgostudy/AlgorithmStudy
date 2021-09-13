#include <bits/stdc++.h>
using namespace std;
#define tp tuple<int, int, int>

map<int, int> res;
map<tp, int> mti;
int a, b, c;

void dfs(tp tup);
void intmap(tp t);

int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> a >> b >> c;
    tp tupt(0, 0, c);
    mti.emplace(tupt, 1);
    dfs(tupt);
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << it->first << ' ';
    }
    return 0;    
}

void intmap(tp t) {
    if (!mti[t]) {
        mti[t] = 1;
        dfs(t);
    }
}

void dfs(tp tup) {
    int a_ = get<0>(tup), b_ = get<1>(tup), c_ = get<2>(tup);
    if (!a_) {
        res[c_] = 1;
    }
    if (c_) {
        int nexta = a - (c_ + a_);
        if (nexta >= 0) {
            tp tupt(c_+a_, b_, 0);
            intmap(tupt);
        } else {
            tp tupt(a, b_, (c_+a_-a));
            intmap(tupt);
        }
        int nextb = b - (c_ + b_);
        if (nextb >= 0) {
            tp tupt(a_, c_+b_, 0);
            intmap(tupt);
        } else {
            tp tupt(a_, b, (c_+b_-b));
            intmap(tupt);
        }
    }    
    if (b_) {
        int nexta = a - (b_ + a_);
        if (nexta >= 0) {
            tp tupt(b_+a_, 0, c_);
            intmap(tupt);
        } else {
            tp tupt(a, (b_+a_-a), c_);
            intmap(tupt);
        }
        int nextc = c - (b_ + c_);
        if (nextc >= 0) {
            tp tupt(a_, 0, c_+b_);
            intmap(tupt);
        } else {
            tp tupt(a_, (b_+c_-c), c);
            intmap(tupt);
        }
    }
    if (a_) {
        int nextb = b - (a_ + b_);
        if (nextb >= 0) {
            tp tupt(0, a_+b_, c_);
            intmap(tupt);
        } else {
            tp tupt((a_+b_-b), b, c_);
            intmap(tupt);
        }
        int nextc = c - (a_ + c_);
        if (nextc >= 0) {
            tp tupt(0, b_, c_+a_);
            intmap(tupt);
        } else {
            tp tupt((a_+c_-c), b_, c);
            intmap(tupt);
        }
    }
    return;
}