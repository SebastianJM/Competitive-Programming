#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
	
    int n,min,aux;
    scanf("%d",&n);
    vector<int> vec=vector<int>(n);
    for(int i=0;i<n;i++)
        scanf("%d",&vec[i]);
    while(true)
    {
		min=*std::min_element(std::begin(vec),std::end(vec));
		if(min==2000)
			break;
		aux=std::count(std::begin(vec),std::end(vec),min);
		std::replace(std::begin(vec),std::end(vec),min,2000);
		printf("%d\n",n);
		n-=aux;
    }
    return 0;
}