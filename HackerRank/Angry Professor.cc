#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T,N,K,aux,sum;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d %d",&N,&K);
        sum=0;
        for(int e=0;e<N;e++)
        {
            scanf("%d",&aux);
            if(aux<=0)
                sum++;
        }
        if(sum>=K)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}