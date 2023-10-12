/******************************************************************************
C++ program to swap two Strings
*******************************************************************************/
#include <iostream>
#include <cstring>

using namespace std;

void mystrcpy(char *d, const char *s)
{
    while (*s)
    {
        *d=*s;
        d++;
        s++;
    }
    *d='\0'; 
}

void myswap(char *s1, char *s2)
{
    char temp[80]; 
    mystrcpy(temp, s1); 
    mystrcpy(s1, s2); 
    mystrcpy(s2, temp); 
}

int main()
{
    char s1[80], s2[80];
    cout<<"Enter the s1 string: ";
    cin.getline(s1, 80);

    cout<<"Enter the s2 string: ";
    cin.getline(s2, 80);

    cout<<"Before swap: "<<endl;
    cout<<"String s1: "<<s1<< endl;
    cout<<"String s2: "<<s2<< endl;

    myswap(s1, s2);

    cout<<"After swap: "<<endl;
    cout<<"String s1: "<<s1<<endl;
    cout<<"String s2: "<<s2<<endl;
    
    return 0;
}
