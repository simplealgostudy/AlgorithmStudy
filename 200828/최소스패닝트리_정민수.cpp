#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MakeNode
{
public:
    int node[2];
    int weight = 0;
    MakeNode(int node1, int node2, int weight)
    {
        this->node[0] = node1;
        this->node[1] = node2;
        this->weight = weight;
    }
    bool operator<(MakeNode &MN)
    { // 연산자 오버로딩을 통해 오름차순으로 정렬될 것을 정의한다.
        return this->weight < MN.weight;
    }
};

int findRoot(int temp[], int t)
{
    if (temp[t] == t)
        return t;
    return temp[t] = findRoot(temp, temp[t]);
}

void merge(int temp[], int t1, int t2)
{
    t1 = findRoot(temp, t1);
    t2 = findRoot(temp, t2);
    if (t1 < t2)
        temp[t2] = t1;
    else
        temp[t1] = t2;
}

bool compareSameRoot(int temp[], int t1, int t2)
{
    t1 = findRoot(temp, t1);
    t2 = findRoot(temp, t2);
    return t1 == t2;
}

int main()
{
    int v; // 정점의 갯수(1 <= v <= 10,000)
    int e; // 간선의 갯수(1 <= v <= 10,000)
    int a; // 정점
    int b; // 정점
    int c; // 두 정점 a와 b사이의 가중치

    cin >> v >> e;

    vector<MakeNode> Node;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        Node.push_back(MakeNode(a, b, c));
    }

    sort(Node.begin(), Node.end());

    int temp[e]; // 각 정점이 포함된 그래프가 어디인지 저장
    for (int i = 0; i < e; i++)
    {
        temp[i] = i;
    }

    int sum = 0;

    for (int i = 0; i < e; i++)
    {
        if (!compareSameRoot(temp, Node[i].node[0] - 1, Node[i].node[1] - 1))
        {
            sum += Node[i].weight;
            merge(temp, Node[i].node[0] - 1, Node[i].node[1] - 1);
        }
        if (e==1){
            sum += Node[i].weight;
        }
    }

    cout << sum;

    return EXIT_SUCCESS;
}
