#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int v, height;
    node *lchild, *rchild;
};

node *newNode(int v);
int getHeight(node *root);
void updateHeight(node *root);
int getBalanceFactor(node *root);
void L(node * &root);
void R(node * &root);
void insert(node * &root, int v);
node *Create(int data[], int N);

int main(int argc, const char *argv[])
{
    int N;
    cin >> N;
    int data[N];
    for(int i = 0; i < N; i++)
        cin >> data[i];
    node *root = Create(data, N);
    cout << root->v << endl;

    return 0;
}

node *newNode(int v)
{
    node * Node = new node;
    Node->height = 1;
    Node->v = v;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

int getHeight(node *root)
{
    if(root == NULL)
        return 0;
    else
        return root->height;
}

void updateHeight(node *root)
{
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBalanceFactor(node *root)
{
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void L(node * &root)
{
    node *tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void R(node * &root)
{
    node *tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void insert(node * &root, int v)
{
    if(root == NULL)
        root = newNode(v);
    else
    {
        if(v < root->v)
        {
            insert(root->lchild, v);
            updateHeight(root);
            if(getBalanceFactor(root) == 2)
            {
                if(getBalanceFactor(root->lchild) == 1)
                    R(root);
                else if(getBalanceFactor(root->lchild) == -1)
                {
                    L(root->lchild);
                    R(root);
                }
            }
        }
        else
        {
            insert(root->rchild, v);
            updateHeight(root);
            if(getBalanceFactor(root) == -2)
            {
                if(getBalanceFactor(root->rchild) == -1)
                    L(root);
                else if(getBalanceFactor(root->rchild) == 1)
                {
                    R(root->rchild);
                    L(root);
                }
            }
        }
    }
}

node *Create(int data[], int N)
{
    node *root = NULL;
    for(int i = 0; i < N; i++)
        insert(root, data[i]);
    
    return root;
}