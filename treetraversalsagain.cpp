#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};
int PreOrder[31], InOrder[31], N;
int cnt = 0;

void getOrder(void);
node * createTree(int PreL, int PreR, int InL, int InR);
void PostTraverse(node *root);

int main(int argc, const char * argv[])
{
    getOrder();
    node * Root = NULL;
    Root = createTree(0, N - 1, 0, N - 1);
    PostTraverse(Root);

    return 0;
}

void getOrder(void)
{
    cin >> N;
    stack<int> S;
    int inindex = 0, preindex = 0;
    for(int i = 0; i < N * 2; i++)
    {
        string str;
        cin >> str;
        if(str == "Push")
        {
            int tmp;
            cin >> tmp;
            S.push(tmp);
            PreOrder[preindex++] = tmp;
        }
        else if(str == "Pop")
        {
            InOrder[inindex++] = S.top();
            S.pop();
        }
    }
}


node * createTree(int PreL, int PreR, int InL, int InR)
{
    if(PreL > PreR)
        return NULL;
    node *root = new node;
    root->data = PreOrder[PreL];
    int i;
    for(i = InL; i <= InR; i++)
        if(InOrder[i] == PreOrder[PreL])
            break;
    root->left = createTree(PreL + 1, PreL + i - InL, InL, i - 1);
    root->right = createTree(PreL + i - InL + 1, PreR, i + 1, InR);

    return root;
}

void PostTraverse(node *root)
{
    if(root)
    {
        PostTraverse(root->left);
        PostTraverse(root->right);
        cout << root->data;
        cnt++;
        if(cnt < N)
            cout << " ";
    }
}