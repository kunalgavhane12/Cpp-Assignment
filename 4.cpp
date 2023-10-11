/******************************************************************************
C++ Program for Return maximum occurring character in the input string
*******************************************************************************/
#include <iostream>

using namespace std;
char maxOccuring(char *p)
{
    int cnt[256]={0};
    
    char maxChar='\0';
    int maxCnt=0;
    
    for(int i=0; p[i]; i++)
    {
        cnt[p[i]]++;
        
        if(cnt[p[i]]>maxCnt)
        {
            maxCnt=cnt[p[i]];
            maxChar=p[i];
        }
    }
    return maxChar;
}

int main()
{
    char str[80],ch;
    cout<<"Enter String:";
    cin.getline(str,80);
    
    ch=maxOccuring(str);
    if(ch!='\0')
    {
        cout<<"Maximum occurring character: "<<ch<<endl;
    }
    else
    {
        cout<<"No characters in the input string."<<ch<<endl;
    }

    return 0;
}