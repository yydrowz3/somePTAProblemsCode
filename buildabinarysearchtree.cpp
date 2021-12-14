#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
    int data;
    int left, right;
};
int N;
int cnt = 0, n = 0;
void InOrder(int root, node Tree[], int num[]);
void BFS(node Tree[], int root);

int main(int argc, const char *atgv[])
{
    cin >> N;
    node Tree[N];
    for(int i = 0; i < N; i++)
        cin >> Tree[i].left >> Tree[i].right;
    int num[N];
    for(int i = 0; i < N; i++)
        cin >> num[i];
    sort(num, num + N);
    InOrder(0, Tree, num);
    BFS(Tree, 0);

    return 0;
}

void InOrder(int root, node Tree[], int num[])
{
    if(root == -1)
        return;
    else
    {
        InOrder(Tree[root].left, Tree, num);
        Tree[root].data = num[cnt++];
        InOrder(Tree[root].right, Tree, num);
    }
}

void BFS(node Tree[], int root)
{
    queue<int> Q;
    if(root != -1)
        Q.push(root);
    while(!Q.empty())
    {
        int tmp = Q.front();
        Q.pop();
        cout << Tree[tmp].data;
        n++;
        if(n < N)
            cout << " ";
        if(Tree[tmp].left != -1)
            Q.push(Tree[tmp].left);
        if(Tree[tmp].right != -1)
            Q.push(Tree[tmp].right);
    }
}