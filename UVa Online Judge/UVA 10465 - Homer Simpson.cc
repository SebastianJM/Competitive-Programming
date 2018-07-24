#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m,t;
	int vec[10005];
	while(cin>>m>>n>>t)
	{
		memset(vec,0,sizeof vec);
		vec[n]=1;
		vec[m]=1;
		for(int i=0;i<=t;i++)
			if(vec[i]>0)
			{
				if(i+n<=t)
					vec[i+n]=max(vec[i+n],vec[i]+1);
				if(i+m<=t)
					vec[i+m]=max(vec[i+m],vec[i]+1);
			}
		int z;
		for(z=t;z>0 && !vec[z];z--);
		if(z==t)
			cout<<vec[z]<<endl;
		else
			cout<<vec[z]<<" "<<t-z<<endl;
	}
	return 0;
}