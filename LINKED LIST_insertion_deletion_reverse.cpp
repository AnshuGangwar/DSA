#include <iostream>

using namespace std;
class Node
{
public:
    int data ;
    //struct Node* next;//struct node is the pointer type
    Node *next;//C++work
};

Node* head = NULL;

void RevRecursion(Node* p)
{

//    cout<<"Elements after reversing using recursion*** "<<endl;
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    RevRecursion(p->next);
    p->next->next=p;
    p->next=NULL;

}

void Reverse (Node *temphead)
{
    Node *prev,*current,*next;
    current = temphead;
    prev = NULL;

    while(current != NULL)
    {
        next= current->next;
        current->next=prev;
        prev = current;
        current =next;
    }
    head = prev;
}

//  deleting  by searching DATA
void Deletebydata(int n)
{
    cout<<"Delete by data :"<<n<<endl;
    Node* temp = head;
    if(head->data == n)
    {
        head= temp->next ;
        delete(temp);
        return;
    }
    while(temp != NULL)
    {
        if(temp->next->data == n)
        {
            cout<<"Found element : "<<n<<endl;
            temp->next = temp->next->next;
            break;
        }
        temp = temp->next;
    }
}



void Deletebyposition(int n)
{

    cout<<"After delete by position :"<<n<<endl;
    Node* temp = head;
    if(n == 1)
    {
        head= temp->next ;
        delete(temp);
        return;
    }

    for(int i =0; i<n-2; i++)
    {
        temp =temp->next;//pointing n-1 th node
    }
    Node* temp2=temp->next;//created new node pointing to nth node
    temp->next =temp2->next;
    delete(temp2);
}

void display()
{

    Node* temp=head;
    while(temp!=NULL)
    {

        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;
}
//INSERT AT FIRST POSITION
/*void insert(int x)
{

    //Node* temp=(Node*) malloc(sizeof(Node)) ;// new_node is pointer type of Node
    Node* temp = new Node();//c++
    temp->data = x;//(*temp).next=x;
    temp->next =head;
    head= temp;

}*/
void insert(int data,int n)
{

    Node* new_node = new Node();//creating new node

    new_node->data = data;//assigning data inside data of new node
    new_node-> next =NULL;
    if(n==1)
    {

        new_node->next =head;
        head= new_node;
        return;
    }

    Node* temp =head;
    for(int i =0; i<n-2; i++)//temp will be pointer to n-1 th node
    {
        temp =temp->next;
    }
    new_node-> next =temp ->next;// next of  NEWLY CREATED NODE NEW_NODE which we wanna insert at nth position  , we set next of n-1 th node(temp)

    temp->next =new_node;
}


int main()
{
    insert(3,1);
    insert(6,2);
    insert(9,2);
    insert(4,4);
    insert(5,4);
    cout<<"Display Linked List"<<endl;
    display();
    Deletebyposition(2);
    display();
    Deletebydata(3);
    display();
    cout<<"Reverse Linked List"<<endl;
    Reverse(head);
    display();
    cout<<"Recursive Reverse Linked List"<<endl;
    RevRecursion(head);
    display();

    return 0;
}
