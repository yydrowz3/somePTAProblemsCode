#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int level;
    vector<int> child;
}Node[110];
int hashTable[110] = {0};
int maxlevel = 0;

void BFS(int root);

int main(int argc, const char * argv[])
{
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int ID, K;
        cin >> ID >> K;
        for(int j = 0; j < K; j++)
        {
            int tmp;
            cin >> tmp;
            Node[ID].child.push_back(tmp);
        }
    }

    BFS(1);

    for(int i = 1; i <= maxlevel; i++)
    {
        cout << hashTable[i];
        if(i < maxlevel)
            cout << " ";
    }
    cout << endl;

    return 0;
}

void BFS(int root)
{
    queue<int> Q;
    Node[root].level = 1;
    Q.push(root);
    while(!Q.empty())
    {
        int tmp = Q.front();
        Q.pop();
        if(Node[tmp].child.size() == 0)
            hashTable[Node[tmp].level]++;
        else
            for(int i = 0; i < Node[tmp].child.size(); i++)
            {
                Node[Node[tmp].child[i]].level = Node[tmp].level + 1;
                if(Node[Node[tmp].child[i]].level > maxlevel)
                    maxlevel = Node[Node[tmp].child[i]].level;
                Q.push(Node[tmp].child[i]);
            }
    }
}
