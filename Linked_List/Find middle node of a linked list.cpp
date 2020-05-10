#include<stdio.h>
#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data =data;
    }
};
//Node* head =NULL;
Node* insert(Node *head, int data,int n )
{
    Node *p = new Node(data);
    if(n==1)
    {
        p->next = head;
        head= p;
    }
    else
    {
        Node *temp =head ;
        for (int i=0; i<n-2; i++)
        {
            temp=temp-> next;
        }
        p->next=temp->next;
        temp->next= p;
    }
    return head;
}

void display(Node *head)
{

    Node* temp=head;
    while(temp!=NULL)
    {

        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;
}
void find_middle(Node* head)
{
    Node *fast = head;
    Node *slow= head;

    if(head==NULL)
    {
        cout<< "NO element "<<endl;
    }
    else
    {
        while(fast !=NULL && fast->next !=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout<< "Middle node is :"<< slow->data;

    }
}


int main()
{
    Node *head = NULL;
    head = insert(head, 1,1);
    head = insert(head, 2,2);
     head = insert(head, 23,3);
    head = insert(head, 21,2);
     head = insert(head, 5,1);
    head = insert(head, 9,2);
    display(head);
    find_middle(head);



    return 0;
}


