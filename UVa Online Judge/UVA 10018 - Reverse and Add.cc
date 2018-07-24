#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,n;
	cin>>t;
	while(t--)
	{
		long long ans=1,rev,aux,i;
		cin>>n;
		while(1)
		{
			aux=n;
			rev=0;
			while(aux>0)
			{
				rev=rev*10+aux%10;
				aux/=10;
			}
			n+=rev;
			
			aux=n;
			rev=0;

			while(aux>0)
			{
				rev=rev*10+aux%10;
				aux/=10;
			}
			
			if(n==rev)
			{
				cout<<ans<<" "<<rev<<endl;
				break;
			}
			ans++;
			 
		}
	}
}