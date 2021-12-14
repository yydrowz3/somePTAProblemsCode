#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int layer;
    int amount = -1;
    vector<int> child;
    double mult;
}Node[100001];
int N;
double P, r;

double BFS(int root);

int main(int argc, const char * argv[])
{
    cin >> N >> P >> r;
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if(num != 0)
            for(int j = 0; j < num; j++)
            {
                int tmp;
                cin >> tmp;
                Node[i].child.push_back(tmp);
            }
        else
        {
            int tmp;
            cin >> tmp;
            Node[i].amount = tmp;
        }
    }
    double sum = BFS(0);
    printf("%.1lf\n", sum);

    return 0;
}


double BFS(int root)
{
    double sum = 0.0;
    queue<int> Q;
    Node[root].layer = 0;
    Node[root].mult = 1.0;
    Q.push(root);
    while(!Q.empty())
    {
        int tmp = Q.front();
        Q.pop();
        if(Node[tmp].child.size() == 0)
        {
            sum += Node[tmp].amount * Node[tmp].mult * P;
        }
        else
            for(int i = 0; i < Node[tmp].child.size(); i++)
            {
                int child = Node[tmp].child[i];
                Node[child].layer = Node[tmp].layer + 1;
                Node[child].mult = Node[tmp].mult * (1 + r / 100);
                Q.push(child);
            }
    }

    return sum;
}