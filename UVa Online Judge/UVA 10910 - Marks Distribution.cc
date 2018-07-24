#include <bits/stdc++.h>

using namespace std;

int main() 
{
	int s,n,t,p;
	long long res[73][73];
	cin>>s;
	while(s--)
	{
		cin>>n>>t>>p;
		memset(res,0,sizeof res);
		for(int i=p;i<=t-(p*n)+p;i++)
			res[1][i]=1;
		for(int i=1;i<=n;i++)
			for(int e=1;e<=t;e++)
				if(res[i][e]>0)
					for(int k=p;k<=t-(p*n)+p;k++)
						if(e+k<=t)
							res[i+1][e+k]+=res[i][e];
		cout<<res[n][t]<<endl;
	}
	return 0;
}