/******************************************************************************
C++ Program for Remove all duplicates from the input string.
******************************************************************************/

#include <iostream>

using namespace std;
string removeAllDuplicate(string s)
{
   string temp="";
   int arr[256]={0};
   for(int i=0; i<s.length(); i++)
   {
       if(arr[s[i]]==0)
       {
           arr[s[i]]=1;
           temp += s[i];
       }
   }
   return temp;
}

int main()
{
    string str;
    cout<<"Enter the string:";
    getline(cin,str);
    cout<<removeAllDuplicate(str)<<endl;

    return 0;
}

