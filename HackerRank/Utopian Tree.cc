#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int T,N,aux,h;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);
        aux=1;
        h=1;
        while(N--)
        {
            if(aux==1)
                h*=2;
            else
                h++;
            aux*=-1;
        }
        printf("%d\n",h);
    }
    return 0;
}