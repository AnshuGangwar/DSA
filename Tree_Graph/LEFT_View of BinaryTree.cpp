
#include <iostream>
using namespace std;

class BstNode
{
public:
    int data;
    BstNode* left;
    BstNode* right;

    BstNode(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void printLeftview(bool *levels, BstNode *root, int curlevel)
{
    if(!root)
    {
        return;
    }

    if(levels[curlevel]==false)//check in array of levels - by default all was false- On visit make true.
    {
        levels[curlevel] = true;
        cout<<root->data<<" ";
    }
    //Interchange these two lines according to  left or right view
    printLeftview(levels,root->left,curlevel+1);    //left child called--LEFT VIEW
    printLeftview(levels,root->right,curlevel+1);   //right child called - call first for RightView of BT


}

void leftView(BstNode *root)
{
    bool levels[] = {false};
    printLeftview(levels,root,0);
}

int main()
{
    BstNode* root = new BstNode(12);
    root->left = new BstNode(10);
    root->right = new BstNode(30);
    root->right->left = new BstNode(25);
    root->right->right = new BstNode(40);
    root->right->right->right = new BstNode(60);

    leftView(root);

    return 0;
}

