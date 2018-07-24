#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t,a,b,c,con;
    int total=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&c);
        con=0;
        if(a==1)
            con++;
        if(b==1)
            con++;
        if(c==1)
            con++;
        if(con>=2)
            total++;
    }
    printf("%d",total);
    return 0;
}