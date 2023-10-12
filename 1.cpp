/******************************************************************************
1.C++ program  to Create Custom function for strlen, strcpy, strchr, strstr  
eg: create functions mystrlen, mystrcpy which behaves in same manner as these 
library functions
*******************************************************************************/

#include <iostream>

using namespace std;

#define size 80

int mystrlen(const char *);
void mystrcpy(const char*,char*);
int mystrchr(const char*,char);
int mystrstr(const char*,const char*);

int main()
{
    int choise;
    do{
        cout<<"1. Mystrlen 2. Mystrcpy 3. Mystrchr 4. Mystrstr 5.exit"<<endl;
        cin>>choise;
        switch(choise)
        {
        /*********************User Define strlen*****************/
        	case 1:
            	char str[size];
                int len;
                cout<<"Enter the string:"<<endl;
                cin.ignore();
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
                break;
        /*********************User Define strcpy*****************/
        	case 2:
            	char source[size],destination[size];
            	cout<<"Enter a source string:"<<endl;
            	cin.ignore();
            	cin.getline(source, size);
            	
            	mystrcpy(source,destination);
            
            	cout<<"Source string: "<<source<<endl;
            	cout<<"Destination string: "<<destination<<endl;
                break;         
        /*********************User Define strchr*****************/
            case 3:
               	char s[size],ch;
               	int index;
               	cout<<"Enter a string: "<<endl;
               	cin.ignore();
               	cin.getline(s,size);
               	cout<<"Enter a character: "<<endl;
               	cin>>ch;
               	
               	index=mystrchr(s,ch);
               	if(index==0)
               	{
               	    cout<<ch<<" is not present"<<endl;
               	}
               	else
               	{
               	    cout<<ch<<" present at index: "<<index+1<<endl;
               	}
               	break;
       /*********************User Define strstr*****************/
            case 4:
               	char main[size],sub[size];
               	cout<<"Enter a main string:"<<endl;
               	cin.ignore();
               	cin.getline(main, size);
               	cout<<"Enter a sub string:"<<endl;
               	cin.ignore();
               	cin.getline(sub, size);
                	
               	if(mystrstr(main,sub))
               	{
               	    cout<<"Sub String is found"<<endl;
               	}
               	else
               	{
               	    cout<<"Sub String is not found"<<endl;
               	}
               	break;
               	case 5:
               	exit(0);
               	default:
               	cout<<"Invalid Input"<<endl;
               	break;
        }
    }while(choise!=5);
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
void mystrcpy(const char *s, char *d)
{
    while(*s)
    {
        *d=*s;
        s++;
        d++;
    }
    *d=*s;
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



