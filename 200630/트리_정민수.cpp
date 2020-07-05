#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> node;
int answer = 0, del_node;
 
void leaf_amount(int now_node)
{
    if (del_node == now_node)
        return;
    int childSize = node[now_node].size();
    switch (childSize)
    {
    case 0:
        answer++; //자신이 자식노드이면서 혼자밖에 없으므로 리턴
        return;
        break;
    case 1:
        if (node[now_node][0] == del_node)
        {
            answer++;
            break;
            //자식노드가 하나뿐인 경우에서, 자식노드가 삭제할 노드인 경우이다.
        }
    default:
        for (int i = 0; i < childSize; i++)
        {
            leaf_amount(node[now_node][i]);
        }
        break;
    }
}
 
int main()
{
    int size, root;
    scanf("%d", &size);
    node.resize(size);
 
    for(int nodeIdx = 0; nodeIdx < size; nodeIdx++)
    {
        int parent;
        scanf("%d", &parent);
        if (parent != -1)
            node[parent].push_back(nodeIdx);
        else
            root = nodeIdx;
        /*
-1 0 0 1 1
 
nodeIdx = 0
parent = -1
root에 0(nodeIdx를 저장)
 
nodeIdx = 1
parent = 0
node[0] = 1
 
nodeIdx = 2
parent = 0
node[0] = 2를 push_back
 
nodeIdx = 3
parent = 1
node[1] = 3
 
nodeIdx = 4
parent = 1
node[1] = 4를 push_back
 
node[0][0] = 1
node[0][1] = 2
node[1][0] = 3
node[1][1] = 4
*/
    }
    scanf("%d", &del_node);
    leaf_amount(root);
    printf("%d", answer);
    return 0;
}
/*노드를 이차원 벡터로 만든다. 
두번째로 입력받는 값들이 부모노드이다.
부모노드.size가 자손노드의 갯수이다.
자손노드의 갯수에 따라 조건을 넣는다.
재귀호출을 하면서 깊이 들어간다.
*/


