#include <bits/stdc++.h>
using namespace std;

#define N 30002
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
	{
		if(vec[a]>1)
			cout<<"There are "<<vec[a]<<" ways to produce "<<a<<" cents change."<<endl;
		else
			cout<<"There is only 1 way to produce "<<a<<" cents change."<<endl;
	}
	
	return 0;
}