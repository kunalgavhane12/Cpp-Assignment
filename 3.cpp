/******************************************************************************
C++ Program to Check if a Given String is Palindrome
*******************************************************************************/
#include <iostream>

using namespace std;
int mystrlen(char *p)
{
    int i=0;
    while(*p)
    {
        i++;
        p++;
    }
    return i;
}

int strPalindrone(char *p)
{
    int len1=mystrlen(p);
    
    for(int i=0,j=len1-1; i<j; i++,j--)
    {
        if(p[i]!=p[j])
        return 0;
    }
    return 1;
}

int main()
{
    char str[80];
    cout<<"Enter a string:";
    cin.getline(str,80);
    if(strPalindrone(str))
    {
        cout<<"String is Palindrome"<<endl;
    }
    else
    {
        cout<<"String not Palindrome"<<endl;
    }

    return 0;
}