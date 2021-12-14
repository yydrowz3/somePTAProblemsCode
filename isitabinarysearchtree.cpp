#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};
int index = 0, cnt = 0;
void insert(node *&root, int x);
void preTraverse(node *root, int preorder[]);
void mirrorTraverse(node *root, int mirrororder[]);
bool judge(int a[], int b[], int N);
void postTraverse(node *root, int N);
void mirrorpostTraverse(node *root, int N);

int main(int argc, const char * argv[])
{
    node *root = NULL;
    int N;
    cin >> N;
    int num[N];

    for(int i = 0; i < N; i++)
    {
        cin >> num[i];
        insert(root, num[i]);
    }
    bool res = true;
    int preorder[N];
    index = 0;
    preTraverse(root, preorder);
    res = judge(num, preorder, N);
    if(res == true)
    {
        cout << "YES" << endl;
        postTraverse(root, N);
    }
    else
    {
        index = 0;
        int mirrororder[N];
        mirrorTraverse(root, mirrororder);
        res = judge(num, mirrororder, N);
        if(res == true)
        {
            cout << "YES" << endl;
            mirrorpostTraverse(root, N);
        }
        else
        {
            cout << "NO" << endl;
        }

    }
    

    return 0;
}

void insert(node *&root, int x)
{
    if(root == NULL)
    {
        root = new node;
        root->data = x;
        root->left = root->right = NULL;
    }
    else
    {
        if(x < root->data)
            insert(root->left, x);
        else
            insert(root->right, x);
    }
}

void preTraverse(node *root, int preorder[])
{
    if(root)
    {
        preorder[index++] = root->data;
        preTraverse(root->left, preorder);
        preTraverse(root->right, preorder);
    }
}

void mirrorTraverse(node *root, int mirrororder[])
{
    if(root)
    {
        mirrororder[index++] = root->data;
        mirrorTraverse(root->right, mirrororder);
        mirrorTraverse(root->left, mirrororder);
    }
}

bool judge(int a[], int b[], int N)
{
    for(int i = 0; i < N; i++)
        if(a[i] != b[i])
            return false;
    return true;
}

void postTraverse(node *root, int N)
{
    if(root)
    {
        postTraverse(root->left, N);
        postTraverse(root->right, N);
        cout << root->data;
        cnt++;
        if(cnt < N)
            cout << " ";
    }
}

void mirrorpostTraverse(node *root, int N)
{
    if(root)
    {
        mirrorpostTraverse(root->right, N);
        mirrorpostTraverse(root->left, N);
        cout << root->data;
        cnt++;
        if(cnt < N)
            cout << " ";
    }
}