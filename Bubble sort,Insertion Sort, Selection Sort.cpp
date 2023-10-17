/******************************************************************************
Bubble Sort, Insertion Sort, Selection Sort
*******************************************************************************/

#include <iostream>

using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubbleSort(int *p, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(p[j]>p[j+1])
            {
                swap(p[j],p[j+1]);
            }
        }
    }
}
void insertionSort(int *p, int n)
{   int i,j;
    for(i=1; i<n; i++)
    {
        int temp=p[i];
        for(j=i; j>0 && p[j-1]>temp; j--)
        {
            p[j]=p[j-1];
        }
        p[j]=temp;
    }
}
void selectionSort(int *p, int n)
{
    int i, j, min;
 
    for (i = 0; i < n - 1; i++)
    {
       min = i;
       j=i+1;
       
       while(j<n)
       {
           if (p[j] < p[min])
           min = j;
           j++;
       }
       if (min != i)
       swap(p[min], p[i]);
    }
}

void input(int *p, int n)
{
    cout<<"Enter array element:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }
}
void display(int *p, int n)
{
    cout<<"Array element: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n=5,choice;
    // cout<<"Enter size: ";
    // cin>>n;
    int arr[n]={50,10,30,70,40};
    while(1)
    {
        cout<<"1. Input 2. Bubble Sort 3. Insertion Sort 4. Selection Sort 5.Display 6.exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            input(arr,n);
            break;
            
            case 2:
            cout<<"Before Sort: "<<endl;
            display(arr,n);
            bubbleSort(arr,n);
            cout<<"After Sort: "<<endl;
            display(arr,n);
            break;
            
            case 3:
            cout<<"Before Sort: "<<endl;
            display(arr,n);
            insertionSort(arr,n);
            cout<<"After Sort: "<<endl;
            display(arr,n);
            break;
            
            case 4:
            cout<<"Before Sort: "<<endl;
            display(arr,n);
            selectionSort(arr,n);
            cout<<"After Sort: "<<endl;
            display(arr,n);
            break;
            
            case 5:
            display(arr,n);
            break;
            case 6:
            exit(0);
            break;
            
            default: 
            cout<<"Invalid Input"<<endl;
            break;
        }
    }
    
    return 0;
}

