/******************************************************************************
C++ Program for Remove characters from the first string which are present in the
second string
*******************************************************************************/
#include <iostream>

using namespace std;

string removeCharacter(string p, string q)
{
    int len1=p.length();
    int len2=q.length();
    string temp="";
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
            i+=len2;
        }
        else
        {
            temp+=p[i];
        }
    }
    return temp;
}
int main()
{
    string s1,s2;
    string res="";
    cout<<"Enter String: ";
    getline(cin,s1);
    
    cout<<"Enter Sub String: ";
    cin>>s2;

    res=removeCharacter(s1,s2);
    cout<<res<<endl;

    return 0;
}
