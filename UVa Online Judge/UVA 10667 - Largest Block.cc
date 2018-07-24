#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,n,c,x1,x2,y1,y2,suma[104][104];
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		memset(suma,0,sizeof suma);
		for(int i=0;i<c;i++)
		{
			cin>>x1>>y1>>x2>>y2;
			for(int j=x1-1;j<=x2-1;j++)
				for(int k=y1-1;k<=y2-1;k++)
					suma[j][k]=1;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(i>0) suma[i][j]+=suma[i-1][j];
				if(j>0) suma[i][j]+=suma[i][j-1];
				if(i>0 && j>0) suma[i][j]-=suma[i-1][j-1];
			}
		int maxSub=-25;
		for(int i=0;i<n;i++) 
			for(int j=0;j<n;j++)
				for(int k=i;k<n;k++)
					for(int l=j;l<n;l++)
					{
						int subRect=suma[k][l];
						if(i>0) subRect-=suma[i-1][l];
						if(j>0) subRect-=suma[k][j-1];
						if(i>0 && j>0) subRect+=suma[i-1][j-1];
						if(subRect==0)
							maxSub=max(maxSub,(k-i+1)*(l-j+1));
					}
		cout<<(maxSub<0?0:maxSub)<<endl;
	}
	return 0;
}