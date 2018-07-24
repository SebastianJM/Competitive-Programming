#include <bits/stdc++.h>
using namespace std;

#define N 30002
int main() 
{
	string a;
	unsigned long long vec[N];
	int moneda[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
	memset(vec,0,sizeof vec);
	vec[0]=1;
	for(int i=0;i<11;i++)
		for(int e=moneda[i];e<N;e++)
			vec[e]+=vec[e-moneda[i]];
	while(cin>>a)
	{
		if(a=="0.00")
			break;
		int b=0,p=0,t=100,s=1;
		for(int i=a.length()-4;i>=0;i--)
		{
			b+=(a[i]-'0')*t;
			p+=(a[i]-'0')*s;
			t*=10;
			s*=10;
		}
		b+=(a[a.length()-2]-'0')*10;
		b+=(a[a.length()-1]-'0');
		printf("%3d.",p);
		cout<<a[a.length()-2]<<a[a.length()-1];
		printf("%17lld\n",vec[b]);
	}
	
	return 0;
}