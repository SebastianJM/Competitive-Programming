#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> vec;
int Minimo(int min,int max)
{
    int m=vec[min];
    for(int i=min;i<=max;i++)
        if(vec[i]<m)
            m=vec[i];
    return m;
}
int main() 
{
    int t,n,min,max;
    scanf("%d %d",&t,&n);
    vec=vector<int>(t);
    for(int i=0;i<t;i++)
        scanf("%d",&vec[i]);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&min,&max);
        printf("%d\n",Minimo(min,max));
    }
    return 0;
}