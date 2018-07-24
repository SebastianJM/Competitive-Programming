#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long maximo(int n)
{
	long long max=0;
	for(int i=0;i<n;i++)
		max+=2*pow(10,i);
	return max;
}
long long minimo(int n)
{
	long long min=2;
	for(int i=1;i<n;i++)
		min+=pow(10,i);
	return min;
}

bool verificar(long long n)
{
	while(n!=0)
	{
		if(n%10<1 || n%10>2)
			return false;
		n/=10;
	}
	return true;
}
int main()
{
    int t,n,e;
	long long maxlim,minlim,it,potencia,max,min;
	cin>>t;
	int caso=0;
	while(caso!=t)
	{
		cin>>n>>e;
		maxlim=maximo(n);
		minlim=minimo(n);
		max=min=0;
		
		potencia=pow(2,e);
		it=minlim/potencia;
		it*=potencia;
		while(it<=maxlim)
		{
			if(it>=minlim && verificar(it))
			{
				min=it;
				break;
			}
			it+=potencia;
		}
		it=maxlim/potencia;
		it*=potencia;
		while(it>=minlim)
		{
			if(it<=maxlim && verificar(it))
			{
				max=it;
				break;
			}
			it-=potencia;
		}
	
		if(max==min && min!=0)
			cout<<"Case "<<caso+1<<": "<<min<<endl;
		else if(min==0)
			cout<<"Case "<<caso+1<<": impossible"<<endl;
		else
			cout<<"Case "<<caso+1<<": "<<min<<" "<<max<<endl;
		caso++;
	}
	getchar();
    return 0;
}