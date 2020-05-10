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

Node* removeloop(Node* head, Node *fast){
  // Node* fast = head;
    Node* slow = head;

    while(slow->next !=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NULL;
}

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
int find_loop(Node* head)
{
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && slow != NULL  && fast-> next != NULL )
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
            {
               removeloop(head,fast);
               return 1;
            }

        }
        return 0;
}


int main()
{
    Node* head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);
    //for testing
    head->next->next->next->next->next = head->next->next;
    int res = find_loop(head);
    cout<<res<<endl;
    res == 0 ? cout<<"No loop" : cout<<"There is a loop"<<endl;

    return 0;
}

