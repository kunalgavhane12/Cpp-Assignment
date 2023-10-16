/******************************************************************************
Linked List Program Add First Middle Last, Delete First, Middle, Last.
*******************************************************************************/

#include <iostream>

using namespace std;

struct Node{
  int data;
  struct Node *next;
};

int countNode(struct Node* head)
{
    int cnt=0;
    while(head!=NULL)
    {
        cnt++;
        head =head->next;
    }
    return cnt;
}
struct Node * createNode(int val)
{
    struct Node *ptr=new (struct Node);
    ptr->data=val;
    ptr->next=NULL;
    return ptr;
}
/******************Adding Node in Linked List*************************/
struct Node * addFirst(struct Node* head,int val)
{
    struct Node *ptr=NULL;
    if(head==NULL)
    return createNode(val);
    else
    {
        ptr=createNode(val);
        ptr->next=head;
        head=ptr;
    }
    return head;
}
struct Node* addMiddle(struct Node*head,int val)
{
    struct Node*ptr=head;
    struct Node *p=createNode(val);
    int cnt=1;//=count(head);
    while(ptr!=NULL)
    {
        cnt++;
        ptr = ptr->next;
        
    }
    ptr=head;
    int i=1;
    struct Node *temp=NULL;
    while(ptr!=NULL)
    {
        if(i==cnt/2)
        {
            temp=ptr->next;
            ptr->next=p;
            p->next=temp;
        }
        ptr = ptr->next;
        i++;
    }
    return head;
}
struct Node * addLast(struct Node* head,int val)
{
    struct Node *ptr=createNode(val);
    struct Node *temp=head;
    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp= temp->next;
        }
        temp->next=ptr;
    }
    return head;
}
struct Node* addAtPosition(struct Node* head, int val, int pos)
{
    struct Node* temp=head;
    int cnt=1;
    while(temp!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    temp=head;
    if(pos<1 || pos>cnt+1)
    {
        cout<<"Invalid Position"<<endl;
    }
    else
    {
        for(int i=1; i<pos-1 && temp!=NULL; i++)
        {
            temp=temp->next;
        }
        struct Node*ptr=createNode(val);
        ptr->next=temp->next;
        temp->next=ptr;
        if(pos==1)
        {
            head=ptr;
        }
        cnt++;
    }
    
    return head;
}
/******************Deleting Node in Linked List*************************/
struct Node* deleteFirst(struct Node* head)
{
    struct Node* ptr=head;
    head=head->next;
    delete ptr;
    return head;
}
struct Node* deleteMiddle(struct Node* head)
{
    struct Node* temp=head;
    
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    int cnt=countNode(head)/2;
    while(cnt>1)
    {
        head=head->next;
        cnt--;
    }
    head->next=head->next->next;
    
    return temp;
}
struct Node* deleteLast(struct Node*head)
{
    struct Node* temp=head;
    struct Node* ptr=NULL;
    if(head==NULL)
    return NULL;
    if(head->next==NULL)
    {
        delete head;
        return head;
    }
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    
    temp->next=NULL;
    delete temp->next;
    
    return head;
}
struct Node* deleteAtPosition(struct Node*head,int pos)
{
    if(pos<1)
    {
        cout<<"Invalid Position"<<endl;
        return head;
    }
    if(pos==1)
    {
        struct Node* ptr=head;
        head=head->next;
        delete ptr;
        return head;
    }
    struct Node* temp=head;
    
    for(int i=1; i<pos-1 && temp!=NULL; i++)
    {
        temp=temp->next;
    }
    struct Node* ptr=temp->next;
    temp->next=ptr->next;
    
    delete ptr;
    
    return head;
}
void traversalList(struct Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main()
{
    struct Node *head=NULL;
    int data,pos;
    int choice;
        do{
            cout<<"1.addFirst 2. addMiddle 3.addLast 4.addAtPosition 5.deleteFirst"
                " 6.deleteMiddle 7.deletelast 8.deleteAtPosition 9.Display 10.exit"<<endl;
                cout<<"Enter your choice:"<<endl;
                cin>>choice;
                switch(choice)
                {
                    case 1:
                    cout<<"Enter Add First data: "<<endl;
                    cin>>data;
                    head=addFirst(head,data);
                    break;
                    
                    case 2:
                    cout<<"Enter Add Middle data: "<<endl;
                    cin>>data;
                    head=addMiddle(head,data);
                    break;
                    
                    case 3:
                    cout<<"Enter Add Last data: "<<endl;
                    cin>>data;
                    head=addLast(head,data);
                    break;
                    
                    case 4:
                    cout<<"Enter Add At Position data: "<<endl;
                    cin>>data;
                    cout<<"Enter position: "<<endl;
                    cin>>pos;
                    head=addAtPosition(head,data,pos);
                    break;
                    
                    case 5:
                    if(head==NULL)
                    {
                        cout<<"List is empty"<<endl;
                    }
                    else
                    {
                        head=deleteFirst(head);
                        cout<<"first Node deleted Successfully"<<endl;
                    }
                    break;
                    
                    case 6:
                    if(head==NULL)
                    {
                        cout<<"List is empty"<<endl;
                    }
                    else
                    {
                        head=deleteMiddle(head);
                        cout<<"Middle Node deleted Successfully"<<endl;
                    }
                    break;
                    
                    case 7:
                    head=deleteLast(head);
                    cout<<"Last Node deleted Successfully"<<endl;
                    break;
                    
                    case 8:
                    cout<<"Enter Delete Node position: ";
                    cin>>pos;
                    head=deleteAtPosition(head,pos);
                    cout<<"At position Node deleted Successfully"<<endl;
                    break;
                    
                    case 9:
                    if(head==NULL)
                    {
                        cout<<"List is Empty"<<endl;
                    }
                    else
                    {
                        traversalList(head);
                    }
                    break;
                    
                    case 10:
                    exit(0);
                    
                    default:
                    cout<<"Invalid Input"<<endl;
                    break;
                }
        }while(choice!=10);
    
    return 0;
}
