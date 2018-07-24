#include <bits/stdc++.h>

using namespace std;

map<int,pair<int,int> > mp;

struct point
{
	int x,y;
	point(){};
};
vector<point> vp;
int adj[202][202];

inline int dist(point a,point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,n,x,y,q=1,dis;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vp=vector<point>(n);
		mp=map<int,pair<int,int> >();
		mp[0].first=0;
		mp[0].second=0;
		int a=0,b=0;
		for(int i=0;i<n;i++)
			cin>>vp[i].x;
		for(int i=0;i<n;i++)
			cin>>vp[i].y;
		for(int i=0;i<n;i++)
			for(int e=0;e<n;e++)
			{
				cin>>adj[i][e];
				if(i!=e)
				{
					dis=dist(vp[i],vp[e]);
			
					(adj[i][e])?mp[dis].second++:mp[dis].first++;
					
				}
			}
		
		int rep=(1<<30),vis;
		map<int,pair<int,int> >::iterator it,itt;
			
		it=mp.begin();
		it++;
		for(itt=mp.begin();it!=mp.end();it++,itt++)
			it->second.first+=itt->second.first;

		it=mp.end();
		it--;
		for(itt=mp.end();it!=mp.begin();it--,itt--)
			it->second.second+=(itt!=mp.end())?itt->second.second:0;
		it->second.second+=itt->second.second;
		
		int aux;
		it=mp.begin(); it++;
		rep=it->second.second;
		vis=0;
		itt=it;
		itt++;
		
		for(;it!=mp.end();it++,itt++)
		{
			aux=it->second.first;
			aux+=(itt!=mp.end())?itt->second.second:0;
			if(aux<rep)
			{
				rep=aux;
				vis=it->first;
			}
		}
		cout<<"Case #"<<q++<<": "<<vis<<" "<<rep<<endl;
		
	}
	return 0;
}