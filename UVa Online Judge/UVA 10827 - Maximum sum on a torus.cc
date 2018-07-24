#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,n,suma[76*2][76*2];
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(suma,0,sizeof suma);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				cin>>suma[i][j];
				suma[i+n][j]=suma[i][j+n]=suma[i+n][j+n]=suma[i][j];
			}
			
		for(int i=0;i<n*2;i++)
			for(int j=0;j<n*2;j++)
			{
				if(i>0) suma[i][j]+=suma[i-1][j];
				if(j>0) suma[i][j]+=suma[i][j-1];
				if(i>0 && j>0) suma[i][j]-=suma[i-1][j-1];
			}
		int maxSub=-750000;
		
		for(int i=0;i<n;i++) 
			for(int j=0;j<n;j++)
				for(int k=i;k<i+n;k++)
					for(int l=j;l<j+n;l++)
					{
						int subRect=suma[k][l];
						if(i>0) subRect-=suma[i-1][l];
						if(j>0) subRect-=suma[k][j-1];
						if(i>0 && j>0) subRect+=suma[i-1][j-1];					
						maxSub=max(maxSub,subRect);
					}
		cout<<maxSub<<endl;
	}
	return 0;
}