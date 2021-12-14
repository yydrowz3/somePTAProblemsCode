#include <iostream>
#include <queue>
using namespace std;

const int maxn = 31;
struct node
{
    int data;
    node * left;
    node * right;
};
int in[maxn], post[maxn];
int n;
node * creat(int postL, int postR, int inL, int inR);
void BFS(node *root);

int main(int argc, const char * argv[])
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> post[i];
    for(int i = 0; i < n; i++)
        cin >> in[i];
    
    node *root = creat(0, n - 1, 0, n - 1);
    BFS(root);
    
    
    return 0;
}


node * creat(int postL, int postR, int inL, int inR)
{
    if(postL > postR)
        return NULL;
    
    node * root = new node;
    root->data = post[postR];
    int i;
    for(i = inL; i <= inR; i++)
        if(in[i] == post[postR])
            break;
    int leftNum = i - inL;
    root->left = creat(postL, postL + leftNum - 1, inL, i - 1);
    root->right = creat(postL + leftNum, postR - 1, i + 1, inR);

    return root;
}

void BFS(node *root)
{
    queue<node *> Q;
    int cnt = 0;
    if(root)
        Q.push(root);
    while(!Q.empty())
    {
        node * tmp = Q.front();
        Q.pop();
        cnt++;
        cout << tmp->data;
        if(cnt < n)
            cout << " ";
        if(tmp->left)
            Q.push(tmp->left);
        if(tmp->right)
            Q.push(tmp->right);
    }

}