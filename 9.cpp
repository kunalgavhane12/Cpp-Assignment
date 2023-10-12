/******************************************************************************
C++ Program for Write your own atoi()
*******************************************************************************/
#include <iostream>

using namespace std;

int myatoi(string p)
{
    int i=0,num=0,flag=0;
    if(p[0]=='-')
    {
        flag=1;
        i++;
    }
    for( ; p[i]; i++)
    {
        if(p[i]=='.')
        break;
        if(!(p[i]>='0'&& p[i]<='9'))
        {
            cout<<"invalid input"<<endl;
            return 0;
        }
        
        num=num*10+p[i]-48;
    }
    if(flag==1)
    num=-num;
    
    return num;
}

int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    
    int num=myatoi(str);
    
    if(num)
    cout<<num<<endl;

    return 0;
}