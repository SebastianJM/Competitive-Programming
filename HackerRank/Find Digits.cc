#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,num,p,aux,can;   
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&num);
        p=num;
        can=0;
        while(num>0)
        {
            aux=num%10;
            if(aux>0)
                if(p%aux==0)
                    can++;
            num/=10;
        }
        printf("%d\n",can);
    }
    return 0;
}