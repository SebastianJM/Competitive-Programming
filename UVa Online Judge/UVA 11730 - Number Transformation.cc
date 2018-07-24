#include <bits/stdc++.h>

using namespace std;

typedef int ll;
#define INF 200000000
ll tamano_criba;
bitset<1002> bs;
vector<ll> primos;
bool visit[1002];
void criba(ll limite)
{
	tamano_criba = limite + 1;
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= tamano_criba; i++)
		if(bs[i])
		{
			for(ll j = i * i; j <= tamano_criba; j += i)
				bs[j] = 0;
			primos.push_back(i);
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	criba(1002);
	vector<vector<int> > g=vector<vector<int> >(1002);
	queue<pair<int,int> > q;
	for(int i=0;i<primos.size();i++)
		for(int e=primos[i]*2;e<=1000;e+=primos[i])
			g[e].push_back(primos[i]);
	ll n,t,f,s,c=1;
	while(cin>>n>>t)
	{
		if(!n && !t)
			break;
		while(!q.empty())
			q.pop();
		memset(visit,0,sizeof visit);
		int ans=n==t?0:INF;
		for(int i=0;i<(int)g[n].size();i++)
			if(n+g[n][i]<=t)
				q.push(make_pair(1,n+g[n][i]));
		
		while(!q.empty())
		{
			f=q.front().first;
			s=q.front().second;
			visit[s]=true;
			q.pop();
			if(s==t)
				ans=min(ans,f);
			else
				for(int i=0;i<(int)g[s].size();i++)
					if(s+g[s][i]<=t && !visit[s+g[s][i]])
						q.push(make_pair(f+1,s+g[s][i]));
		}
		
		cout<<"Case "<<c++<<": "<<(ans==INF?-1:ans)<<endl;
	}
	return 0;
}