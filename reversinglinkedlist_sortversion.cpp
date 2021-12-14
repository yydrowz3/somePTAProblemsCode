#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;
struct Node
{
    int address, data, next;
    int order = maxn;  //结点在链表上的序号，无效标为maxn
}node[maxn];

bool cmp(Node a, Node b);


int main(int argc, const char * argv[])
{
    int begin, n, k, address;
    scanf("%d%d%d", &begin, &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    int p = begin, count = 0;
    while(p != -1)
    {
        node[p].order = count++;
        p = node[p].next;
    }

    sort(node, node + maxn, cmp);

    n = count;
    for(int i = 0; i < n / k; i++)
    {
        for(int j = (i + 1) * k - 1; j > 1; j--)    //第i块倒着输出
            printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
        printf("%05d %d ", node[i * k].address, node[i * k].data);
        if(i < n / k - 1)
            printf("%05d\n", node[(i + 2) * k - 1].address);
        else
        {
            if(n % k == 0)  //恰好是最后一个
                printf("-1\n");
            else    //剩下的不完整块按原先顺序输出
            {
                printf("%05d\n", node[(i + 1) * k].address);
                for(int i = n / k * k; i < n; i++)
                {
                    printf("%05d %d ", node[i].address, node[i].data);
                    if(i < n - 1)
                        printf("%05d\n", node[i + 1].address);
                    else
                        printf("-1\n");
                }
            }
            
        }
    }

    return 0;
}

bool cmp(Node a, Node b)
{
    return a.order < b.order;
}