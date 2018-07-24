#include <bits/stdc++.h>
using namespace std;
int r;
char mat[40][90];
int x[4] = {0, 0, -1, 1};
int y[4] = {-1, 1, 0, 0};

void dfs(int i,int j)
{
	mat[i][j]='#';
	for(int k=0;k<4;k++)
		if( mat[i+x[k]][j+y[k]]==' ')
		{
			mat[i+x[k]][j+y[k]]='#';
			dfs(i+x[k],j+y[k],p);
		}
}
int main()
{	
	int t;
	cin>>t;
	getchar();
	while(t--)
	{
		r=0;	
		while(1)
		{
			gets(mat[r]);
			if(mat[r][0]=='_')
				break;
			r++;
		}
		bool ya=false;
		for(int i=0;i<r;i++)
		{
			int lon=strlen(mat[i]);
			for(int j=0;j<lon;j++)
				if(mat[i][j]=='*')
					dfs(i,j);

		}
		for(int i=0;i<r+1;i++)
		{
			for(int j=0;j<strlen(mat[i]);j++)
				cout<<mat[i][j];
			cout<<endl;
		}
		memset(mat,0,sizeof mat);
	}
	return 0;
}