#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi strength,champ;
int main() 
{
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		strength=vi(2*(1<<n));
		champ=vi(2*(1<<n));
		for(int i=0;i<(1<<n);i++)
		{
			cin>>strength[(1<<n)+i];
			champ[(1<<n)+i]=i+1;
		}
		int a,b;
		for(int i=n-1;i>=0;i--)
		{
			for(int j=1<<i;j<1<<(i+1);j++)
			{
				a=j<<1;
				b=(j<<1)+1;
				if(strength[a]>=strength[b])
				{
					champ[j]=champ[a];
					strength[j]=strength[a]-strength[b];
					
				}
				else
				{
					champ[j]=champ[b];
					strength[j]=strength[b]-strength[a];
					
				}
				strength[j]+=(strength[j]+k>strength[(1<<n)+champ[j]-1])?(strength[(1<<n)+champ[j]-1]-strength[j]):k;
			}
		}
		cout<<champ[1]<<endl;
		
		k=(1<<n)+champ[1]-1;
		bool spa=false;
		while(k>1)
		{
			if(spa)
				cout<<" ";
			spa=true;
			if(k&1)
				cout<<champ[k-1];
			else
				cout<<champ[k+1];
			k>>=1;
		}
		
		cout<<endl;
	}
	return 0;
}
