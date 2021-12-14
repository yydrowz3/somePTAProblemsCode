#include <iostream>
#include <vector>
using namespace std;

int N, K, P, maxSum = -1;
vector<int> num, ans, tmp;
void init(void);
void DFS(int index, int n, int sum, int total);

int main(int argc, const char * argv[])
{
    cin >> N >> K >> P;
    init();
    DFS(num.size() - 1, 0, 0, 0);
    if(maxSum == -1)
        cout << "Impossible" << endl;
    else
    {
        cout << N << " = " << ans[0] << "^" << P;
        for(int i = 1; i < K; i++)
            cout << " + " << ans[i] << "^" << P;
        cout << endl;
    }

    return 0;
}

void init(void)
{
    for(int i = 0; ; i++)
    {
        int m = 1;
        for(int j = 0; j < P; j++)
            m *= i;
        if(m > N)
            break;
        else
            num.push_back(m);
    }
}

void DFS(int index, int n, int sum, int total)
{
    if(sum == N && n == K)
    {
        if(total > maxSum)
        {
            ans = tmp;
            maxSum = total;
        }
    }
    else if(sum > N || n > K)
        return;
    else
    {
        if(index >= 1)
        {
            tmp.push_back(index);
            DFS(index, n + 1, sum + num[index], total + index);
            tmp.pop_back();
            DFS(index - 1, n, sum, total);
        }
    }
}