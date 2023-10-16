/******************************************************************************
Linked List Add in sorted order and reverse Linked list
*******************************************************************************/
#include <iostream>

using namespace std;
struct Node{
    int data;
    struct Node *next;
};
struct Node *createNode(int val)
{
    struct Node *ptr= new (struct Node);
    ptr->data=val;
    ptr->next=NULL;
    return ptr;
}
struct Node* addInsorted(struct Node*  head,int val)
{
    struct Node* ptr=createNode(val);
    struct Node* prev= NULL;
    struct Node* cur=head;
    
    if(head==NULL)
    {
        head=ptr;
        return head;
    }
    while(cur && cur->data < ptr->data)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev==NULL)
    {
        ptr->next=head;
        head=ptr;
    }
    else
    {
        ptr->next=cur;
        prev->next=ptr;
        
    }
    
    return head;
}
struct Node* ReverseLinkedList(struct Node* head)
{
    struct Node *prev=NULL;
    struct Node *cur=head;
    struct Node *temp=NULL;
    while(cur!=NULL)
    {
        temp=cur->next;
        cur->next=prev;
        
        prev=cur;
        cur=temp;
    }
    head=prev;
    return head;
}
void traversalLinkedList(struct Node* head)
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
int main()
{
  struct Node *head=NULL;
  int choice,data;
  do{
      cout<<"1.Add in Sorted 2.Reverse Linked List 3.Display 4.exit"<<endl;
      cout<<"Enter the choice:"<<endl;
      cin>>choice;
      
      switch(choice)
      {
          case 1:
          cout<<"Enter the data: "<<endl;
          cin>>data;
          head=addInsorted(head,data);
          break;
          
          case 2:
            cout<<"Before Reverse Linked List: "<<endl;
            traversalLinkedList(head);
            head=ReverseLinkedList(head);
            cout<<"After Reverse Linked List: "<<endl;
            traversalLinkedList(head);
          break;
          
          case 3:
          traversalLinkedList(head);
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