/******************************************************************************
1.C++ program  to Create Custom function for strlen, strcpy, strchr, strstr  
eg: create functions mystrlen, mystrcpy which behaves in same manner as these 
library functions
*******************************************************************************/

#include <iostream>

using namespace std;

#define size 80

int mystrlen(const char *);
void mystrcpy(char *d, const char *s);
int mystrchr(const char*,char);
int mystrstr(const char*,const char*);
int main()
{
    /*********************User Define strlen*****************/
    	char str[size];
        int len;
        cout<<"Enter the string:"<<endl;
        cin.getline(str, size);
        len=mystrlen(str);
        if(len==0)
        {
            cout<<"string is empty"<<endl;
        }
        else
        {
            cout<<"String length: "<<len<<endl;
        }
    /*********************User Define strcpy*****************/
    	char source[size],destination[size];
    	cout<<"Enter a source string:"<<endl;
    	cin.getline(source, size);
    	
    	mystrcpy(destination,source);
    
    	cout<<"Source string: "<<source<<endl;
    	cout<<"Destination string: "<<destination<<endl;
 
    /*********************User Define strchr*****************/
  
       	char s[size],ch;
       	cout<<"Enter a string: "<<endl;
       	cin.getline(s,size);
       	cout<<"Enter a character: "<<endl;
       	cin>>ch;
       	cin.ignore();
       	
       	int index=mystrchr(s,ch);
       	if(index==0)
       	{
       	    cout<<ch<<" is not present"<<endl;
       	}
       	else
       	{
       	    cout<<ch<<" present at index: "<<index+1<<endl;
       	}
   /*********************User Define strstr*****************/
       	char main[size],sub[size];
       	cout<<"Enter a main string:"<<endl;
       	cin.getline(main, size);
       	cout<<"Enter a sub string:"<<endl;
       	cin.getline(sub, size);
        	
       	if(mystrstr(main,sub))
       	{
       	    cout<<"Sub String is found"<<endl;
       	}
       	else
       	{
       	    cout<<"Sub String is not found"<<endl;
       	}
   
	return 0;
	
}

int mystrlen(const char *p)
{
	int i=0;
	while(*p)
	{
	i++;
	p++;
    }
    return i;
}
void mystrcpy(char *d, const char *s)
{
    while (*s!='\0')
    {
        *d=*s;
        d++;
        s++;
    }
    *d='\0'; 
}
int mystrchr(const char *p,char ch)
{
    for(int i=0; p[i]; i++)
    {
        if(p[i]==ch)
        return i;
    }
    return 0;
}
int mystrstr(const char *p, const char *q)
{
    int len1=mystrlen(p);
    int len2=mystrlen(q);
    int cnt=0;
    if(!len2)
    {
        return 0;
    }
    for(int i=0; i<len1; i++)
    {
        if(p[i]==q[0])
        {
            int j=0;
            for( ; j<len2; j++)
            {
                if(p[i+j]!=q[j])
                break;
            }
            if(j==len2)
            return i;
        }
    }
    return 0;
}


