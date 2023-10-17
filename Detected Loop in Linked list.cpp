/******************************************************************************
Detected Loop in Linked list
*******************************************************************************/

#include <iostream>

using namespace std;
typedef struct Node{
    int data;
    struct Node *next;
}SLL;

SLL *createNode(int val)
{
    SLL *ptr=new (SLL);
    ptr->data=val;
    ptr->next=NULL;
    return ptr;
}
SLL* detectedLoop(SLL *head)
{
    SLL *slow=head;
    SLL *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast)
        return slow;
    }
    return NULL;
}
void TraversalLinkedList(SLL *head)
{
    if(head==NULL)
    {
        cout<<"List is Empty"<<endl;
    }
    else
    {
        while(head)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
        cout<<endl;
    }
}
int main()
{
    SLL *head,*p1,*p2,*p3,*p4,*p5;
    head=createNode(10);
    p1=createNode(50);
    p2=createNode(30);
    p3=createNode(40);
    p4=createNode(60);
    p5=createNode(20);
    //Linking Linked List
    head->next=p1;
    p1->next=p2;
    p2->next=p3;
    p3->next=p4;
    p4->next=p5;
    cout<<"Linked list before loop detected : "<<endl;
    TraversalLinkedList(head);
    if(detectedLoop(head))
    {
        cout<<"Loop found"<<endl;
    }
    else
    {
        cout<<"Loop Not found"<<endl;
    }
    
    
    //Creating Loop in Linked List
    p5->next=p2;
    // TraversalLinkedList(head);//Inifite Loop if Traverse 
    cout<<"Linked list after loop detected : "<<endl;
    
    if(detectedLoop(head))
    {
        cout<<"Loop found"<<endl;
    }
    else
    {
        cout<<"Loop Not found"<<endl;
    }
    //Loop disconnected in linked list
    p5->next=NULL;
    
    cout<<"Linked list after loop disconnected : "<<endl;
    TraversalLinkedList(head);

    return 0;
}

