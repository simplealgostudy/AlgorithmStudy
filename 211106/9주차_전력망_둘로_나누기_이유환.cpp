#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> g[101];
bool visit[101] = {false};

int bfs(int start) {
    bool visitT[101] = {false};
    queue<int> q;
    q.push(start);

    int cnt = 0;
    visitT[start] = true;

    while (!q.empty()) {        
        int node = q.front();
        q.pop();

        cnt++;

        for (int i = 0; i < g[node].size(); i++) {
            if (!visit[g[node][i]] && !visitT[g[node][i]]) {

                q.push(g[node][i]);
                visitT[g[node][i]] = true;
            }
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> wires) {

    for (int i = 0; i < n - 1; i++) {
        g[wires[i][0]].push_back(wires[i][1]);
        g[wires[i][1]].push_back(wires[i][0]);
    }

    int answer = 202;
    for (int i = 0; i < n - 1; i++) {
        visit[wires[i][0]] = true;
        visit[wires[i][1]] = true;

        int tmp = bfs(wires[i][0]) - bfs(wires[i][1]);
        answer = min(answer, abs(tmp)); 

        visit[wires[i][0]] = false;
        visit[wires[i][1]] = false;
    }

    return answer;
}
