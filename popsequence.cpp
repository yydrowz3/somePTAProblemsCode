#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

int main(int argc, const char * argv[])
{
    int N, M, K;
    cin >> M >> N >> K;
    for(int i = 0; i < K; i++)
    {
        int sequence[N];
        int cur = 0;
        stack<int> s;
        for(int j = 0; j < N; j++)
            cin >> sequence[j];
        for(int j = 1; j <= N; j++)
        {
            s.push(j);
            if(s.size() > M)
                break;
            while(!s.empty() && s.top() == sequence[cur])
            {
                cur++;
                s.pop();
            }
        }
        if(cur == N)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }



    return 0;
}