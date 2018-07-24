#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

char mat[505][505];
bool vis[505][505];
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
int w,h;
int maxx,minx,maxy,miny;
int ans=0;
void flood(int a,int b)
{
	ans++;
	vis[a][b]=true;
	for(int i=0;i<4;i++)
		if(x[i]+a>=0 && x[i]+a<w && y[i]+b>=0 && y[i]+b<h && mat[x[i]+a][y[i]+b]=='X' && !vis[x[i]+a][y[i]+b])
		{
			vis[x[i]+a][y[i]+b]=true;
			flood(x[i]+a,y[i]+b);
		}
}
int main() 
{
	memset(vis,false,sizeof vis);
	cin>>w>>h;
	minx=100000;
	maxx=0;
	miny=100000;
	maxy=0;
	for(int i=0;i<w;i++)
		for(int j=0;j<h;j++)
		{
			cin>>mat[i][j];
			if(mat[i][j]=='X')
			{
				minx=min(minx,i);
				maxx=max(maxx,i);
				miny=min(miny,j);
				maxy=max(maxy,j);
			}
		}

	for(int i=0;i<w;i++)
		for(int j=0;j<h;j++)
			if(mat[i][j]=='X')
			{
				flood(i,j);
				if((maxx-minx+1)*(maxy-miny+1)!=ans)
					cout<<"NO"<<endl;
				else
					cout<<"YES"<<endl;
				return 0;
			}
	cout<<"NO"<<endl;
	
	return 0;
}