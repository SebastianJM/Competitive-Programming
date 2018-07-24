#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int tamVec(char vec[])
{
    int i=0;
    while(vec[i]!=0)
        i++;
    return i;
}

int main()
{       
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        char vec[101];      
        gets(vec);
        int tam=tamVec(vec);
        if(tam>10)
            printf("%c%d%c\n",vec[0],tam-2,vec[tam-1]);
        else
            puts(vec);  
    }
    return 0;
}