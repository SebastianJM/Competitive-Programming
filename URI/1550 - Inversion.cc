#include <bits/stdc++.h>
using namespace std;

int n,a,b;
bool visit[100002];
int invert(int s)
{
	int i=0;
	while(s>0)
	{
		i*=10;
		i+=s%10;
		s/=10;
	}
	return i;
}
int bfs()
{
	queue<pair<int,int> > q;
	q.push(make_pair(a,0));
	int f,s,inv,one;
	while(!q.empty())
	{
		f=q.front().first;
		s=q.front().second;
		q.pop();
		visit[f]=true;
		if(f==b)
			return s;
		inv=invert(f);
		one=f+1;
		if(!visit[inv])
			q.push(make_pair(inv,s+1));
		if(!visit[one])
			q.push(make_pair(one,s+1));
	}
	return 0;
}
int main() 
{
	
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		memset(visit,0,sizeof visit);
		cout<<bfs()<<endl;
	}
	return 0;
}