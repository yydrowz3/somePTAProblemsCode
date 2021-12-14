#include <iostream>
#include <algorithm>
using namespace std;

int cnt = 0;
void InOrder(int root, int num[], int CBT[], int N);

int main(int argc, const char *argv[])
{
    int N;
    cin >> N;
    int num[N], CBT[N + 1];
    for(int i = 0; i < N; i++)
        cin >> num[i];
    sort(num, num + N);
    InOrder(1, num, CBT, N);
    for(int i = 1; i <= N; i++)
    {
        cout << CBT[i];
        if(i < N)
            cout << " ";
    }
    cout << endl;

    return 0;
}

void InOrder(int root, int num[], int CBT[], int N)
{
    if(root > N)
        return;
    else
    {
        InOrder(root * 2, num, CBT, N);
        CBT[root] = num[cnt++];
        InOrder(root * 2 + 1, num, CBT, N);
    }
}