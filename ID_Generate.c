#include <stdio.h>
#include <string.h>

static int count[256] = {0};
char output[50];
    
char *genrateId(char *name)
{
    char id[20] = "v22he5"; 
    count[name[0]]++;
    sprintf(output, "%s%c%d\n", id, name[0], count[name[0]]);
  
    return output;
}

int main()
{
    
    char name[20];
    char *p=NULL;
    int i = 5;
    while(i--)
    {
        printf("Enter name: ");
        fgets(name, 20, stdin);
        p = genrateId(name);
        printf("%s\n",p);   
        
    }
    return 0;
}