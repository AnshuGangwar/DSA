        // Binary Search Tree - Implementation in C++
// Simple program to create a BST of integers and search an element in it
#include<iostream>
#include<queue>
#include<stack>
#include<climits>//for int max,int min
using namespace std;
//Definition of Node for Binary search tree
class BstNode
{
public:
    int data;
    BstNode* left;
    BstNode* right;

    BstNode(int data){
    this->data = data;
    this->left = this->right = NULL;
    }
};
BstNode* root = NULL;


// To insert data in BST, returns address of root node
BstNode* Insert(BstNode* root,int data)
{// empty tree
    if(root == NULL){root = new BstNode(data);}
    // if data to be inserted is lesser, insert in left subtree.
    else if(data <= root->data){root->left = Insert(root->left,data);}
    // else, insert in right subtree.
    else{root->right = Insert(root->right,data);}
    return root;
}
//To search an element in BST, returns true if element is found
bool Search(BstNode* root,int data)
{
    if(root == NULL){return false;}
    else if(root->data == data){return true;}
    else if(data <= root->data){return Search(root->left,data);}
    else{return Search(root->right,data);}
}

//DFS- Inorder, pre-order, post-order
void InorderRec(BstNode* root)
{
    if(root == NULL){return;}
    InorderRec(root->left);
    cout<<root->data<<" ";
    InorderRec(root->right);
}
// DFS- PREorder//use stack
void Preorder(BstNode *root)
{
    if(root == NULL){return;}
    stack<BstNode*> Q;
    Q.push(root);
    //while there is at least one discovered node
    while(!Q.empty()){
        BstNode* current = Q.top();
        // removing the element at front
        cout<<current->data<<" ";
        Q.pop();
        if(current->right != NULL)
            Q.push(current->right);
        if(current->left != NULL)
            Q.push(current->left);

    }
}
// DFS- inorder//use stack
void Inorder(BstNode *root)
{
    if(root == NULL){return ;}
    stack<BstNode*> S;
    BstNode  *current = root;
    while(!S.empty() || current!=NULL)
    {

        while(current!=NULL)
        {
            S.push(current);
            current=current->left;
        }

        current = S.top();
        S.pop();

        cout<<current->data<<" ";
        current=current->right ;
    }
}
// DFS- Preorder//use stack
void Postorder(BstNode *root)
{
    if(root == NULL)
    {
        return ;
    }
    stack<BstNode*> S1, S2;
    BstNode  *current = root;
    S1.push(root);
    while(!S1.empty())
    {
        BstNode *temp=S1.top();
        S1.pop();
        S2.push(temp);
        if(temp->left!=NULL)
        {
            S1.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            S1.push(temp->right);
        }

    }
    while(!S2.empty())
    {
        BstNode *temp=S2.top();
        cout<<temp->data<<" ";
        S2.pop();
    }
}

void PreorderRec(BstNode* root)
{
    if(root == NULL){return;}
    cout<<root->data<<" ";
    PreorderRec(root->left);
    PreorderRec(root->right);
}
void PostorderRec(BstNode* root)
{
    if(root == NULL){return;}
    PostorderRec(root->left);
    PostorderRec(root->right);
    cout<<root->data<<" ";
}
// BFS- Level order//use queue
void LevelOrder(BstNode *root)
{
    if(root == NULL){return;}
    queue<BstNode*> Q;
    Q.push(root);
    //while there is at least one discovered node
    while(!Q.empty()){
        BstNode* current = Q.front();
        // removing the element at front
        cout<<current->data<<" ";
        if(current->left != NULL)
            Q.push(current->left);
        if(current->right != NULL)
            Q.push(current->right);
        Q.pop();
    }
}
BstNode* findMin(BstNode* root){
    if(root == NULL){return NULL;}
    else if(root->left == NULL){return root;}
    findMin(root->left);
}

BstNode* findMax(BstNode* root)
{
    if(root == NULL){return NULL;}
    if(root->right == NULL){return root;}
    findMax(root->right);
}

int findHeight(BstNode* root)
{
    if(root == NULL){return -1;}
    int heightLeft = findHeight(root->left);
    int heightRight = findHeight(root->right);
    return max(heightLeft,heightRight) + 1;
}

BstNode* Delete(BstNode* root, int data){
    if(root == NULL){return NULL;}
    else if(data < root->data){root->left = Delete(root->left, data);}
    else if(data > root->data){root->right = Delete(root->right, data);}
    else{//Case 1:No Child
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;//root is dangling point still contain address so set NULL
        }//case2:One child
        else if(root-> left == NULL){
            BstNode* temp = root;//store root in temp
            root = root->right;//right child became root of subtree
            delete temp;
        }
        else if(root-> right == NULL){
            BstNode* temp = root;
            root = root->left;//left child became root of subtree
            delete temp;
        }//Case3: 2 child
        else{
            BstNode* temp = findMin(root->right);// find minimum value in right subtree and store in temp
            root->data = temp->data;//set that min data to the root i want to delete
            root->right = Delete(root->right, temp->data);//deleting this value from right subtree --avoid duplicate
        }
    }
    return root;
}
//check for Binary search tree
bool IsBst(BstNode* root,int minValue, int maxValue)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data>minValue && root->data<maxValue
            && IsBst(root->left,minValue, root->data) //data will be in between min value to  max(root value)
            && IsBst(root->right,root->data, maxValue))//data will be in between min value(root data ) to  max value
        return true;

    else
       return false;

}
bool IsBinarySearchTree(BstNode* root)
{
    return IsBst(root,INT_MIN,INT_MAX);
}



int main()
{
    // Creating an empty tree
    /*Code to test the logic*/
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    cout<<"********Inorder traversal**********"<<endl;
    InorderRec(root);
    cout<<endl<<"********Inorder iteration traversal**********"<<endl;
    Inorder(root);
    cout<<endl<<"********Preorder traversal**********"<<endl;
    PreorderRec(root);
    cout<<endl<<"********Preorder iteration traversal**********"<<endl;
    Preorder(root);
    cout<<endl<<"********Postorder traversal**********"<<endl;
    PostorderRec(root);
    cout<<endl<<"********Postorder iteration  traversal**********"<<endl;
    Postorder(root);

    cout<<endl<<"==========Level Order traversal============"<<endl;
    LevelOrder(root);
    // Ask user to enter a number.
    int number;
    cout<<endl<<"Enter number be searched\n";
    cin>>number;
    //If number is found, print "FOUND"
    if(Search(root,number) == true)
        cout<<"Found\n";
    else
        cout<<"Not Found\n";

    cout<<"Min element "<<findMin(root)->data<<endl;
    cout<<"Max element "<<findMax(root)->data<<endl;
    cout<<"Find Height "<<findHeight(root)<<endl;

    int data;
    cout<<endl<<"Enter number to be deleted"<<endl;
    cin>>data;
    Delete(root,data);


    cout<<endl<<"check for BST: ";
    cout<<IsBinarySearchTree(root)<<endl;

}
