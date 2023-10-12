/******************************************************************************
C++ Program for compressing a string 
eg 1)input:”AABCCCDDEEEFF” output:A2B1C3D2E4F2    
eg2) input : “IOOOLLLRRRRRTHHH” output: I1O3L3R5T1H3
*******************************************************************************/
#include <iostream>

using namespace std;

string compressString(string &s)
{
    string temp;
    int cnt=1;
    for(int i=0; i<s.length(); i++)
    {
        if(i+1 < s.length() && s[i]==s[i+1])
        {
            cnt++;
        }
        else
        {
            temp+=s[i]+to_string(cnt); 
            cnt=1;
        }
    }
    return temp;
}

int main()
{
    string str;
    cout<<"Enter the strig: ";
    getline(cin,str);
    
    str=compressString(str);
    cout<<str<<endl;

    return 0;
}