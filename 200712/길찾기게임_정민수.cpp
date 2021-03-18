#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
 
using namespace std;
 
class Tree
{
public:
    int x;
    int y;
    int data;
    Tree *left;
    Tree *right;
 
    Tree(int x, int y, int data)
    {
        this->x = x;
        this->y = y;
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~Tree()
    {
        delete this;
    }
};
void makeSomeNode(Tree *node, Tree *newNode)
{
            //조건에서 모든 노드는 서로 다른 x값을 가진다고 했으므로, x값이 같은 경우는 고려하지 않아도 된다.
    if (node->x < newNode->x)
    { //새 노드의 x값이 크면
        if (node->right == NULL)
        { //오른쪽 노드가 없으면
            node->right = newNode;
        }
        else{
            makeSomeNode(node->right, newNode);
        }
    }
    else if (node->x > newNode->x)
    { //새 노드의 x값이 작으면
        if (node->left == NULL)
        { //왼쪽 노드가 없으면
            node->left = newNode;
        }
        else{
            makeSomeNode(node->left, newNode);
        }
    }
    return; //x값이 같은 경우는 트리로 만들지 않는다
}
void preorder(Tree *node, vector<int> &ans)
{
    if (node)
    {
        ans.push_back(node->data);
        preorder(node->left, ans);
        preorder(node->right, ans);
    }
    else
        return;
}
 
void postorder(Tree *node, vector<int> &ans)
{
    if (node)
    {
        postorder(node->left, ans);
        postorder(node->right, ans);
        ans.push_back(node->data);
    }
    else
        return;
}
bool cmp(Tree *a, Tree *b)
{
    if(a->y==b->y){//y좌표가 같은 경우에는 x값이 작은게 앞에 와야 한다.
        return a->x < b->x;
    }
    return a->y > b->y;//y값이 다른 경우에는 y값이 큰 게 앞에 와야 한다.
}
 
 
 vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer(2);
    vector<Tree *> t(nodeinfo.size());
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        t[i] = new Tree(nodeinfo[i][0], nodeinfo[i][1], i + 1);
        //nodeinfo[i][0]는 x좌표
        //nodeinfo[i][1]는 y좌표
        //데이터 인덱스는 1부터 시작하므로 데이터는 i+1이 들어간다.
    }
    sort(t.begin(), t.end(), cmp);
    for (int i = 1; i < t.size(); i++)
    {
        makeSomeNode(t[0], t[i]); //root노드와 새 노드를 연결한다.
    }
    preorder(t[0], answer[0]);
    postorder(t[0], answer[1]);
    return answer;
}
 
int main()
{
    vector<vector<int>> n = {{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}};
    solution(n);
}


