#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n,i,ans;
	bool prime;
	
	while(cin>>n)
	{
		prime=false;
		for(i=n;i>1;i--)
		{
			prime=true;
			for(int k=2;k<=(int)sqrt(i);k++)
				if(i%k==0)
				{
					prime=false;
					break;
				}
			if(prime)
			{
				ans=i;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}