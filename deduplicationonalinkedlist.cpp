#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int Address, Key, Next;
}List[100001];

int main(int argc, const char * argv[])
{
    int N, Start;
    bool HashTable[10001] = {false};
    scanf("%d%d", &Start, &N);
    for(int i = 0; i < N; i++)
    {
        int add;
        scanf("%d", &add);
        scanf("%d%d", &List[add].Key, &List[add].Next);
    }
    List[100000].Next = -1;
    int p = Start, q = -1, del = 100000;
    while(p != -1)
    {
        int val = abs(List[p].Key);
        if(HashTable[val] == false)
        {
            HashTable[val] = true;
            q = p;
            p = List[p].Next;
        }
        else
        {
            List[q].Next = List[p].Next;
            int tmp = p;
            p = List[p].Next;
            List[tmp].Next = List[del].Next;
            List[del].Next = tmp;
            del = tmp;
        }
    }
    
    for(int i = Start; i != -1; i = List[i].Next)
    {
        printf("%05d %d ", i, List[i].Key);
        if(List[i].Next == -1)
            printf("%d\n", List[i].Next);
        else
            printf("%05d\n", List[i].Next);
    }
    for(int i = List[100000].Next; i != -1; i = List[i].Next)
    {
        printf("%05d %d ", i, List[i].Key);
        if(List[i].Next == -1)
            printf("%d\n", List[i].Next);
        else
            printf("%05d\n", List[i].Next);
    }

    return 0;
}