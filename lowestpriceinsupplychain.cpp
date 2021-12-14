#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> Node[100001];
int minDepth = -1, minNum = -1;

void DFS(int index, int depth);

int main(int argc, const char * argv[])
{
    int N;
    double P, r;
    cin >> N >> P >> r;
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        for(int j = 0; j < num; j++)
        {
            int tmp;
            cin >> tmp;
            Node[i].push_back(tmp);
        }
    }
    DFS(0, 0);

    printf("%.4lf %d\n", pow(1 + r / 100, minDepth) * P, minNum);

    return 0;
}

void DFS(int index, int depth)
{
    if(Node[index].size() == 0)
    {
        if(minDepth == -1)
        {
            minDepth = depth;
            minNum = 1;
        }
        else
        {
            if(depth < minDepth)
            {
                minDepth = depth;
                minNum = 1;
            }
            else if(depth == minDepth)
                minNum++;
        }
    }
    else
    {
        for(int i = 0; i < Node[index].size(); i++)
            DFS(Node[index][i], depth + 1);
    }
}

