#include <bits/stdc++.h>
using namespace std;

int R,C,m[102][102];
int color[102][102];

void dfs(int y,int x,int col)
{
	color[y][x]=col;
	if(y+1<R && m[y][x]==m[y+1][x] && color[y+1][x]==-1)
		dfs(y+1,x,col);
	if(y-1>=0 && m[y][x]==m[y-1][x] && color[y-1][x]==-1)
		dfs(y-1,x,col);
	if(x+1<C && m[y][x]==m[y][x+1] && color[y][x+1]==-1)
		dfs(y,x+1,col);
	if(x-1>=0 && m[y][x]==m[y][x-1] && color[y][x-1]==-1)
		dfs(y,x-1,col);
}

bool nuevaCaraH(int y,int x)
{
	if(m[y][x]==m[y-1][x])
		return false;
	/*if(m[y][x]==m[y-1][x] && m[y][x-1]==m[y-1][x-1] && m[y][x]==m[y][x-1])
		return false;*/
	if(m[y][x-1]<m[y-1][x-1] && m[y][x]<m[y-1][x] && m[y-1][x]>m[y][x-1] && m[y-1][x-1]>m[y][x])
		return false;
	if(m[y][x-1]>m[y-1][x-1] && m[y][x]>m[y-1][x] && m[y-1][x]<m[y][x-1] && m[y-1][x-1]<m[y][x])
		return false;
	return true;
}

bool nuevaCaraV(int y,int x)
{
	if(m[y][x]==m[y][x-1])
		return false;
	/*if(m[y][x]==m[y-1][x] && m[y][x-1]==m[y-1][x-1] && m[y][x]==m[y][x-1])
		return false;*/
	if(m[y-1][x]<m[y-1][x-1] && m[y][x]<m[y][x-1] && m[y][x]<m[y-1][x-1] && m[y-1][x]<m[y][x-1])
		return false;
	if(m[y-1][x]>m[y-1][x-1] && m[y][x]>m[y][x-1] && m[y][x]>m[y-1][x-1] && m[y-1][x]>m[y][x-1])
		return false;
	return true;
}

int main() 
{
	int ans,aux;
	while(cin>>R>>C)
	{
		for(int i=0;i<R;i++)
			for(int e=0;e<C;e++)
				cin>>m[i][e];
		ans=5;
		//CARAS HORIZONTALES
		if(C>1)
		{
			for(int i=1;i<R;i++)
			{
				if(R>1 && C>1 && m[i][0]!=m[i-1][0])
					ans++;
					
				for(int e=1;e<C;e++)
					if(nuevaCaraH(i,e))
						ans++;
			}
		}
		else
		{
			for(int i=1;i<R;i++)
				if(m[i][0]!=m[i-1][0])
					ans++;
		}
		//cout<<"hori "<<ans<<endl;
		//CARAS VERTICALES
		if(R>1)
		{
			for(int i=1;i<C;i++)
			{
				if(R>1 && C>1 && m[0][i]!=m[0][i-1])
			 		ans++;
				
				for(int e=1;e<R;e++)
					if(nuevaCaraV(e,i))
						ans++;
			}
		}
		else
		{
			for(int i=1;i<C;i++)
				if(m[0][i]!=m[0][i-1])
					ans++;
		}	
		//cout<<"verti "<<ans<<endl;
		memset(color,-1,sizeof color);
		int col=0;
		for(int i=0;i<R;i++)
			for(int e=0;e<C;e++)
				if(color[i][e]==-1)
				{
					dfs(i,e,col);
					col++;
					ans++;
				}
		cout<<ans<<endl;
		
	}
	return 0;
}