#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int address;
    int key = 0x7fffffff;
    int next;
    bool flag = false;
}node[100001];

bool cmp(Node a, Node b);

int main(int argc, const char * argv[])
{
    int N, head;
    scanf("%d%d", &N, &head);
    for(int i = 0; i < N; i++)
    {
        int address, key, next;
        scanf("%d%d%d", &address, &key, &next);
        node[address].address = address;
        node[address].key = key;
        node[address].next = next;
    }
    int cnt = 0, p = head;
    while(p != -1)
    {
        cnt++;
        node[p].flag = true;
        p = node[p].next;
    }
    
    sort(node, node + 100001, cmp);
    if(cnt != 0)
        printf("%d %05d\n", cnt, node[0].address);
    else
        printf("%d -1\n", cnt);
    for(int i = 0; i < cnt; i++)
    {
        if(i < cnt - 1)
            printf("%05d %d %05d\n", node[i].address, node[i].key, node[i + 1].address);
        else
            printf("%05d %d -1\n", node[i].address, node[i].key);
    }
    

    return 0;
}

bool cmp(Node a, Node b)
{
    if(a.flag == false || b.flag == false)
        return a.flag > b.flag;
    else
        return a.key < b.key;
}