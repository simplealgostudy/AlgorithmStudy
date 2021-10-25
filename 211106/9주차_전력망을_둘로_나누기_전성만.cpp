#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    int m = wires.size();
    vector<vector<int>> v(n+1);
    for (int i = 0; i < m; ++i) {
        int a = wires[i][0], b = wires[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < m; ++i) {
        vector<bool> chk(n+1);
        int start[2] = {wires[i][0], wires[i][1]};
        chk[start[0]] = 1;
        chk[start[1]] = 1;
        int cmp[2];
        for (int j = 0; j < 2; ++j) {
            int cnt = 1;
            queue<int> q;
            q.push(start[j]);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int k = 0; k < v[cur].size(); ++k) {
                    if (!chk[v[cur][k]]) {
                       ++cnt;
                        chk[v[cur][k]] = 1;
                        q.push(v[cur][k]);
                    }
                }
            }
            cmp[j] = cnt;
        }        
        answer = min(answer, abs(cmp[0] - cmp[1]));
    }
    return answer;
}