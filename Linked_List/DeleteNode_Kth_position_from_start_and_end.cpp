
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
Node* Deletefromstart(Node *head, int k)
{

    cout<<"Delete by position from start :"<<k<<endl;
    Node* temp = head;
    if(k == 1)
    {
        head= temp->next ;
        delete(temp);

    }
    else
    {
        for(int i =0; i<k-2; i++)
        {
            temp =temp->next;//pointing n-1 th node
        }

        Node* temp2;//creating new node to keep access via pointer in order to delete the node
        temp2=temp->next;//created new node pointing to nth node
        temp->next =temp2->next;
        delete(temp2);
    }
    return head;
}
Node* DeleteFromEnd(Node *head, int k)
{
    cout<<"Delete by position from end  :"<<k<<endl;
    Node *slow =head;
    Node *fast =head;

    for(int i =1; i<=k+1; i++)
    {
        fast=fast->next;
    }
    while(fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=slow->next->next;

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

Node* insert( Node* head,int data,int n )
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

int main()
{
    Node *head = NULL;
    head = insert(head, 1,1);
    head = insert(head, 2,2);
    head = insert(head, 3,3);
    head = insert(head, 12,2);
    display(head);

   // head=Deletefromstart(head,3);
    head=DeleteFromEnd(head,2);
    display(head);
    return 0;
}

