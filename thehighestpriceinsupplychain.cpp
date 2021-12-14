#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> Node[100001];
int maxDepth = 0, maxNum = 0;
void DFS(int index, int depth);
int N;
double P, r;

int main(int argc, const char * argv[])
{
    int root = 0;
    scanf("%d%lf%lf", &N, &P, &r);
    r = r / 100;
    for(int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp != -1)
            Node[tmp].push_back(i);
        else
            root = tmp;
    }
    cout << root << endl;
    DFS(root, 0);
    printf("%.2lf %d\n", pow(1 + r, maxDepth) * P, maxNum);

    return 0;
}

void DFS(int index, int depth)
{
    if(Node[index].size() == 0)
    {
        if(depth > maxDepth)
        {
            maxDepth = depth;
            maxNum = 1;
        }
        else if(depth == maxDepth)
        {
            maxNum++;
        }
        return;
    }
    for(int i = 0; i < Node[index].size(); i++)
        DFS(Node[index][i], depth + 1);
}