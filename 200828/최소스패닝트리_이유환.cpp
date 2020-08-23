#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//나동빈 강의 (크루스칼 알고리즘) 참고
//크루스칼 알고리즘 사용
int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int *parent, int x, int y) {
	x = getParent(parent, x);
	y = getParent(parent, y);

	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int findParent(int parent[], int x, int y) {
	x = getParent(parent, x);
	y = getParent(parent, y);

	if (x == y) return 1;
	return 0;
}

class Edge{
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator < (Edge& edge) {
		return this->distance < edge.distance;
	}
};

int main() {
	int answer = 0;
	int v = 0, e = 0;
	int a = 0, b = 0, c = 0;
	// 정점 : a b , 가중치 : c
	cin >> v >> e;
	vector<Edge> graph;
	
	for (int i = 0; i < e; i++) {
		
		cin >> a >> b >> c;
		graph.push_back(Edge(a, b, c));
	}
	
	sort(graph.begin(), graph.end());

	int* parent = new int[v];
	for (int i = 0; i < v; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < graph.size(); i++){
		if (findParent(parent, graph[i].node[0] - 1, graph[i].node[1] - 1) == 0) {
			answer += graph[i].distance;
			unionParent(parent, graph[i].node[0] - 1, graph[i].node[1] - 1);
		}
	}

	cout << answer << endl;

	delete[] parent;
}
