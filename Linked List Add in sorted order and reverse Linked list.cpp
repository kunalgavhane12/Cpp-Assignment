/*****************************************************************************
 Linked List InsertINsorted order and Reverse Linked list
*******************************************************************************/

#include <iostream>

using namespace std;

typedef struct Node{
    int data;
    struct Node* next;
}SLL;

SLL* createNode(int val)
{
    SLL *ptr=new (SLL);
    ptr->data=val;
    ptr->next=NULL;
    return ptr;
}
SLL *insertInSorted(SLL *head,int val)
{
    SLL *ptr=createNode(val);
    SLL *prev=NULL;
    SLL *cur=head;
    if(head==NULL)
    {
        head=ptr;
        return head;
    }
    while(cur && cur->data < ptr->data)
    {
        prev = cur;
        cur=cur->next;
    }
    if(prev==NULL)
    {
        ptr->next=head;
        head=ptr;
    }
    else
    {  
        prev->next=ptr;
    }
    
    return head;
}
SLL * reverse(SLL * head)
{
     SLL *prev=NULL,*cur=NULL,*ptr=NULL;
     ptr=head;
     while(ptr)
     {
           prev=cur;
           cur=ptr;
    
           ptr=ptr->next;
           cur->next=prev;
     }
     head=cur;
    return head;
}
void traversalList(SLL *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    SLL *head=NULL;
    int data,choice;
    do{
        cout<<"1.insertInSorted 2.Reverse 3.Display 4.exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter data: ";
            cin>>data;
            head=insertInSorted(head, data);
            break;
            
            case 2:cout<<"before reverse"<<endl;
            traversalList(head);
            head=reverse(head);
            cout<<"after reverse"<<endl;
            traversalList(head);
            break;
            
            case 3:
            traversalList(head);
            break;
            
            case 4:
            exit(0);
            
            default:
            cout<<"Invalid Input"<<endl;
            break;
        }
    }while(choice!=4);
    
    return 0;
}