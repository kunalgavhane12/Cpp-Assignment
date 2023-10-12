/******************************************************************************
C++ program to swap two Strings
*******************************************************************************/
#include <iostream>
#include <cstring>

using namespace std;

void mystrcpy(string &d, const string &s)
{
    d=s;
}

void myswap(string &str1, string &str2)
{
    string temp=""; 
    mystrcpy(temp, str1); 
    mystrcpy(str1, str2); 
    mystrcpy(str2, temp); 
}

int main()
{
    string s1, s2;
    cout<<"Enter the s1 string: ";
    getline(cin,s1);

    cout<<"Enter the s2 string: ";
    getline(cin,s2);

    cout<<"Before swap: "<<endl;
    cout<<"String s1: "<<s1<< endl;
    cout<<"String s2: "<<s2<< endl;

    myswap(s1, s2);

    cout<<"After swap: "<<endl;
    cout<<"String s1: "<<s1<<endl;
    cout<<"String s2: "<<s2<<endl;
    
    return 0;
}
