/******************************************************************************
QuickSort in Array
*******************************************************************************/
#include <iostream>

using namespace std;
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partation(int *p, int low, int high)
{
    int Pivot=p[low];
    int i=low+1;
    int j=high;
    do{
        
        while(p[i]<=Pivot)
        {
            i++;
        }
        while(p[j]>Pivot)
        {
            j--;
        }
        if(i<j)
        swap(p[i],p[j]);
        
    }while(i<j);
    
    swap(p[low],p[j]);
    
    return j;
}

void quickSort(int *p, int low, int high)
{
    int PI;
    if(low<high)
    {
        PI=partation(p,low,high);
        quickSort(p,low,PI-1);
        quickSort(p,PI+1,high);
    }
}
void display(int *p,int n)
{
    for(int i=0; i<n; i++)
    cout<<p[i]<<" ";
    cout<<endl;
}
int main()
{
    int arr[]={10,5,25,17,8,45,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Before sort Array Element: ";
    display(arr,n);
    quickSort(arr,0,n-1);
    cout<<"After sort Array Element: ";
    display(arr,n);
    return 0;
}