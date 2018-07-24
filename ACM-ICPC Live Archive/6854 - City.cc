#include <bits/stdc++.h>

using namespace std;

int m[502][502];
bool visit[502][502];
int px[4]={0,0,1,-1};
int py[4]={1,-1,0,0};
int f,c,x,y;
queue<pair<int,pair<int,int> > > q;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>f>>c;
		for(int i=0;i<f;i++)
			for(int e=0;e<c;e++)
			{
				cin>>m[i][e];
				visit[i][e]=false;
				if(m[i][e]==-1)
					y=i,x=e;
			}
		while(!q.empty())
			q.pop();
		int ans=0;
		visit[y][x]=true;
		pair<int,pair<int,int> > p;
		pair<int,pair<int,int> > a;
		p.first=0;
		p.second.first=x;
		p.second.second=y;
		q.push(p);
		while(!q.empty())
		{
			p=q.front();
			q.pop();
			
			for(int k=0;k<4;k++)
				if(p.second.second+py[k]>=0 && p.second.second+py[k]<f && p.second.first+px[k]>=0 && p.second.first+px[k]<c && !visit[p.second.second+py[k]][p.second.first+px[k]])
				{
					visit[p.second.second+py[k]][p.second.first+px[k]]=true;
					if(p.first & 1)
						ans-=m[p.second.second+py[k]][p.second.first+px[k]];
					else
						ans+=m[p.second.second+py[k]][p.second.first+px[k]];
					a.first=p.first+1;
					a.second.second=p.second.second+py[k];
					a.second.first=p.second.first+px[k];
					q.push(a);
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}