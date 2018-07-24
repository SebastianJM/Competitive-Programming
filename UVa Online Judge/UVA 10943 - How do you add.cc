#include <bits/stdc++.h>

using namespace std;

int main() 
{
	int n,t;
	unsigned long long res[103][103];

	while(1)
	{
		cin>>t>>n;
		if(!t && !n)
			return 0;
		memset(res,0,sizeof res);
		for(int i=0;i<=t;i++)
			res[1][i]=1;
		for(int i=1;i<=n;i++)
			for(int e=0;e<=t;e++)
				if(res[i][e]>0)
					for(int k=0;k<=t;k++)
						if(e+k<=t)
							res[i+1][e+k]+=res[i][e]%1000000;
		cout<<res[n][t]%1000000<<endl;
	}
	return 0;
}