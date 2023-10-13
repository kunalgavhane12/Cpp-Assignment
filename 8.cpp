/******************************************************************************
 C++ Program for Reverse words in a given string  eg: “THIS IS A BIG STRING” 
 input : ”BIG” output:”GIB”
*******************************************************************************/
#include <iostream>

using namespace std;

int subStringReveese(string &p,string &q)
{
    int len1=p.length();
    int len2=q.length();
    
    for(int i=0; i<len1; i++)
    {
        int flag=1;
        for(int j=0; j<len2; j++)
        {
            if(p[i+j]!=q[j])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            for(int j=0; j<len2/2; j++)
            {
                char temp=p[i+j];
                p[i+j]=p[i+len2-j-1];
                p[i+len2-j-1]=temp;
            }
            return 1;
        }
    }
    return 0;
}

int main()
{

    string s1,s2;
    cout<<"Enter the string:"<<endl;
    getline(cin,s1);
    cout<<"Enter sub string: "<<endl;
    cin>>s2;
    
    cout<<"string : \n"<<s1<<endl;
    
    int n=subStringReveese(s1,s2);
    
    if(n)
    {
        cout<<"after sub string reverse: \n"<<s1<<endl;
    }
    else
    {
        cout<<"Sub string not found"<<endl;
    }
    
    return 0;
}
