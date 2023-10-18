
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void input(int *p, int n)
{
    srand(time(0));
    for(int i=0; i<n; i++)
    {
        p[i]=rand()%100;
    }
}

void display(int *p, int n)
{
    for(int i=0; i<n; i++)
    cout<<p[i]<<" ";
    cout<<endl;
}

void merge(int *p, int mid, int low, int high)
{
    int i=low,j=mid+1,k=low;
    int temp[100];
    
    while(i<=mid && j<=high)
    {
        if(p[i]<p[j])
        {
            temp[k]=p[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=p[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        temp[k]=p[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        temp[k]=p[j];
        j++;
        k++;
    }
    for(int i=low; i<=high; i++)
    {
        p[i]=temp[i];
    }
}
void mergeSort(int *p,int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(p,low,mid);
        mergeSort(p,mid+1,high);
        merge(p,mid,low,high);
    }
}

int main()
{
    int n;
    cout<<"Enter Array Size: ";
    cin>>n;
    int arr[n];
    input(arr,n);
    cout<<"Before Sorting Array Element:"<<endl;
    display(arr,n);
    mergeSort(arr,0,n-1);
    cout<<"After Sorting Array Element:"<<endl;
    display(arr,n);
    return 0;
}

