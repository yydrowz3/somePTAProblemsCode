#include <iostream>
using namespace std;

struct Node
{
    char data;
    int next;
    bool flag = false;
}node[100001];

int main(int argc, const char * argv[])
{
    int head1, head2, N, p;
    scanf("%d%d%d", &head1, &head2, &N);
    for(int i = 0; i < N; i++)
    {
        int index, nextindex;
        char data;
        scanf("%d %c %d", &index, &data, &nextindex);
        node[index].data = data;
        node[index].next = nextindex;
        
    }
    p = head1;
    while(p != -1)
    {
        node[p].flag = true;
        p = node[p].next;
    }
    p = head2;
    while(p != -1)
    {
        if(node[p].flag == true)
            break;
        p = node[p].next;
    }

    if(p != -1)
        printf("%05d\n", p);
    else
        printf("-1\n");

    return 0;
}