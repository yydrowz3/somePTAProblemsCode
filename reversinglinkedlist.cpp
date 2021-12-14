#include <iostream>
using namespace std;

struct Node
{
    int data;
    int next;
}List[100001];

void Reversing(int Head, int K);

int main(int argc, const char * argv[])
{
    int Head, N, K;
    scanf("%d%d%d", &Head, &N, &K);
    for(int i = 0; i < N; i++)
    {
        int address;
        scanf("%d", &address);
        scanf("%d%d", &List[address].data, &List[address].next);
        // cin >> address;
        // cin >> List[address].data >> List[address].next;
    }
    List[100000].next = Head;
    Reversing(100000, K);
    int p = List[100000].next;
    while(p != -1)
    {
        printf("%05d %d ", p, List[p].data);
        if(List[p].next == -1)
            printf("%d\n", List[p].next);
        else
            printf("%05d\n", List[p].next);
        p = List[p].next;
    }


    return 0;
}


void Reversing(int Head, int K)
{
    int cnt = 0, p = List[Head].next;
    int start = Head;

    while(p != -1)
    {
        p = List[p].next;
        cnt++;
        if(cnt == K)
        {
            int q1, q2, tmphead = List[start].next;
            q1 = List[tmphead].next;
            q2 = tmphead;
            while(q1 != p)
            {
                int tmp = q1;
                q1 = List[q1].next;
                List[tmp].next = q2;
                q2 = tmp;
            }
            List[start].next = q2;
            List[tmphead].next = p;
            start = tmphead;
            cnt = 0;
        }
    }

}