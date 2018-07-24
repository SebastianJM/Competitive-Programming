#include <bits/stdc++.h>

using namespace std;

#define MAX 103
int M[MAX][MAX],f,c;
bool vis[MAX][MAX],freq[MAX];
int x[8]={0,0,1,-1,-1,-1,1,1};
int y[8]={1,-1,0,0,1,-1,-1,1};
int flood(int a,int b)
{
	vis[a][b]=true;
	int z=1;
	for(int i=0;i<8;i++)
	{
		if(a+x[i]<f && a+x[i]>=0 && b+y[i]<c && b+y[i]>=0 && M[a][b]==M[a+x[i]][b+y[i]]&& !vis[a+x[i]][b+y[i]])
		{
			vis[a+x[i]][b+y[i]]=true;
			z+=flood(a+x[i],b+y[i]);
		}
	}
	return z;
}
int main() 
{
	int t,ans;
	cin>>t;
	while(t--)
	{
		cin>>f>>c;
		memset(vis,false,sizeof vis);
		memset(freq,false,sizeof freq);
		for(int i=0;i<f;i++)
			for(int j=0;j<c;j++)
			{
				cin>>M[i][j];
				if(M[i][j]<0)
					vis[i][j]=true;
			}
		
		ans=0;
		for(int i=0;i<f;i++)
			for(int j=0;j<c;j++)
			{
				if(flood(i,j)>1 && !freq[M[i][j]])
				{
					freq[M[i][j]]=true;
					ans++;
				}
					
			}
		cout<<ans<<"\n";
	}
	return 0;
}