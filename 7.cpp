/******************************************************************************
 C++ Program for reversing a string
*******************************************************************************/
#include <iostream>

using namespace std;

void mystrRev(string &p)
{
    char temp;
    int len=p.length();
    for(int i=0;i<len/2; i++)
    {
        temp=p[i];
        p[i]=p[len-i-1];
        p[len-i-1]=temp;
    }
}

int main()
{
    string str;
    cout<<"Enter the string"<<endl;
    getline(cin,str);
    cout<<"Before reverse : "<<str<<endl;
    mystrRev(str);
    cout<<"After reverse : "<<str<<endl;
}
