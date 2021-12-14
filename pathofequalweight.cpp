#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 101;
struct node
{
    int weight;
    vector<int> child;
}Node[MAXN];
int N, M, S;
int path[MAXN];

bool cmp(int a, int b);
void DFS(int index, int numNode, int sum);

int main(int argc, const char *argv[])
{
    cin >> N >> M >> S;
    for(int i = 0; i < N; i++)
        cin >> Node[i].weight;
    for(int i = 0; i < M; i++)
    {
        int index, n;
        cin >> index >> n;
        for(int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            Node[index].child.push_back(tmp);
        }
        sort(Node[index].child.begin(), Node[index].child.end(), cmp);
    }
    path[0] = 0;
    DFS(0, 1, Node[0].weight);

    return 0;
}

bool cmp(int a, int b)
{
    return Node[a].weight > Node[b].weight;
}

void DFS(int index, int numNode, int sum)
{
    if(sum > S)
        return;
    if(sum == S)
    {
        if(Node[index].child.size() != 0)
            return;
        for(int i = 0; i < numNode; i++)
        {
            cout << Node[path[i]].weight;
            if(i < numNode - 1)
                cout << " ";
            else
                cout << endl;
        }

        return;
    }
    for(int i = 0; i < Node[index].child.size(); i++)
    {
        path[numNode] = Node[index].child[i];
        DFS(Node[index].child[i], numNode + 1, sum + Node[Node[index].child[i]].weight);
    }
}