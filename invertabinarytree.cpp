#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int left;
    int right;
}node[11];
int N;
int count = 0;

int getNode(void);
void LevelTraverse(int root);
void InOrderTraverse(int root);

int main(int argc, const char *argv[])
{
    int root = getNode();
    LevelTraverse(root);
    cout << endl;
    InOrderTraverse(root);
    cout << endl;

    return 0;
}

int getNode(void)
{
    cin >> N;
    bool hashTable[N] = {false};
    for(int i = 0; i < N; i++)
    {
        char l, r;
        getchar();
        scanf("%c %c", &l, &r);
        if(l == '-')
            node[i].right = -1;
        else
        {
            node[i].right = l - '0';
            hashTable[l - '0'] = true;
        }
        if(r == '-')
            node[i].left = -1;
        else
        {
            node[i].left = r - '0';
            hashTable[r - '0'] = true;
        }
    }
    for(int i = 0; i < N; i++)
        if(hashTable[i] == false)
            return i;
    return -1;
}

void LevelTraverse(int root)
{
    int cnt = 0;
    queue<int> Q;
    if(root != -1)
        Q.push(root);
    while(!Q.empty())
    {
        int tmp = Q.front();
        Q.pop();
        cout << tmp;
        cnt++;
        if(cnt < N)
            cout << " ";
        if(node[tmp].left != -1)
            Q.push(node[tmp].left);
        if(node[tmp].right != -1)
            Q.push(node[tmp].right);
    }
}

void InOrderTraverse(int root)
{
    if(root != -1)
    {
        InOrderTraverse(node[root].left);
        cout << root;
        count++;
        if(count < N)
            cout << " ";
        InOrderTraverse(node[root].right);
    }
}