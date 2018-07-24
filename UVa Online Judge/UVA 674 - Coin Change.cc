#include <bits/stdc++.h>
using namespace std;

#define N 8000
int main() 
{
	int a;
	unsigned long long vec[N];
	int moneda[5]={1,5,10,25,50};
	memset(vec,0,sizeof vec);
	vec[0]=1;
	for(int i=0;i<5;i++)
		for(int e=moneda[i];e<N;e++)
			vec[e]+=vec[e-moneda[i]];
	while(cin>>a)
		cout<<vec[a]<<endl;
	
	return 0;
}