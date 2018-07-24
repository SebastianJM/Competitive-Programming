// DYNAMIC PROGRAMMING - RANGE SUM 2D - 27/04/2016

#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,f,c,k,mat[32][32];
	char q;
	cin>>t;
	while(t--)
	{
		cin>>f>>c>>k;
		
		memset(mat,0,sizeof mat);
		for(int i=0;i<f;i++)
			for(int j=0;j<c;j++)
			{
				cin>>q;
				if(i>0) mat[i][j]+=mat[i-1][j];
				if(j>0) mat[i][j]+=mat[i][j-1];
				if(i>0 && j>0) mat[i][j]-=mat[i-1][j-1];
				if(q=='C') mat[i][j]++;
			}
		if(!k)
			cout<<0<<"\n";
		else
		{
			int minSub=INT_MAX,subRect;
			for(int i=0;i<f;i++) for(int j=0;j<c;j++)
				for(int v=i;v<f;v++) for(int b=j;b<c;b++)
				{
					subRect=mat[v][b];
					if(i>0) subRect-=mat[i-1][b];
					if(j>0) subRect-=mat[v][j-1];
					if(i>0 && j>0) subRect+=mat[i-1][j-1];
					if(subRect==k)
						minSub=min(minSub,(v-i+1)*(b-j+1));
				}
			if(minSub==INT_MAX)
				cout<<"-1\n";
			else 
				cout<<minSub<<"\n";
		}
	}
	return 0;
}