/******************************************************************************
Merge Two different Linked list in sorted order
*******************************************************************************/
#include <iostream>

using namespace std;
typedef struct Node{
    int data;
    struct Node *next;
}SLL;

void traversalList(SLL *head)
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
        cout<<endl;
    }
}
SLL * createNode(int val)
{
    SLL *ptr=new SLL;
    ptr->data=val;
    ptr->next=NULL;
    return ptr;
}
SLL *insertNode(SLL *head, int val)
{
    SLL *newNode=createNode(val);
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        newNode->next=head;
        head=newNode;
    }
    return head;
}

void sortList(SLL **head)
{
    SLL *cur=*head;
    SLL *temp=*head;
    while(cur->next!=NULL)
    {
        temp=cur->next;
        while(temp!=NULL)
        {
            if(cur->data > temp->data)
            {
                int p=temp->data;
                temp->data=cur->data;
                cur->data=p;
            }
            temp=temp->next;
        }
        cur=cur->next;
    }
}
SLL *mergeAndSort(SLL *head1, SLL *head2)
{
    SLL* temp=head1;
    
    while(temp->next!=NULL && head2!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head2;
    
    sortList(&head1);
    return head1;
}
int main()
{
    SLL *head=NULL,*head1=NULL,*head2=NULL;
    int choice,data;
    while(1)
    {
        cout<<"1.Insert Node in Head1 2.Insert Node in Head2 3.Merge and Sort 4.display 5.exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter data: ";
            cin>>data;
            head1=insertNode(head1,data);
            break;
           
            case 2:
            cout<<"Enter data: ";
            cin>>data;
            head2=insertNode(head2,data);
            break;
           
            case 3: 
            cout<<"Before Merge Linked list :"<<endl;
            traversalList(head1);
            traversalList(head2);
            head=mergeAndSort(head1,head2);
            cout<<"After Merge Linked list :"<<endl;
            traversalList(head);
            break;
           
            case 4:
            traversalList(head);
            break;
           
            case 5:
            exit(0);
            default:
            cout<<"Invalid Input"<<endl;
            
        }
    }
    
    return 0;
}
