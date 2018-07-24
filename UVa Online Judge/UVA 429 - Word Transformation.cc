#include <bits/stdc++.h>
using namespace std;

#define INF 20000000
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
vvii g;
vi dist;
vi preva;
int n;

void init()
{
	preva = vi(n, -1);
	dist = vi(n, INF);
}
void dijkstra(int s)
{
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	dist[s] = 0;
	while (!pq.empty())
	{
		int d = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if (dist[v] >= d)
			for (int i = 0; i < (int)g[v].size(); i++)
			{
				int u = g[v][i].second;
				int w = g[v][i].first;
				if (dist[v] + w < dist[u])
				{
					dist[u] = dist[v] + w;
					preva[u] = v;
					pq.push(ii(dist[u], u));
				}
			}
	}
}
bool unaLetraDif(string a,string b)
{
	if(a.length()!=b.length())
		return false;
	int c=0;
	for(int i=0;i<a.length();i++)
		if(a[i]!=b[i])
			c++;
	if(c==1)
		return true;
	return false;
}
int main()
{
	int t,e,pri=1;
	string s,a,b;		
	//freopen ("out.txt","w",stdout);
	cin>>t;
	getchar();
	while(t--)
	{
		map<string,int> indices;
		vector<string> words;
		g=vvii();
		e=0;
		cin>>a;
		if(pri)
			pri=0;
		else
			cout<<endl;
		
		while(a!="*")
		{
			indices[a]=e++;
			g.push_back(vii());
			for(int i=0;i<words.size();i++)
			{
				if(unaLetraDif(a,words[i]))
				{
					g[e-1].push_back(ii(1,indices[words[i]]));
					g[indices[words[i]]].push_back(ii(1,e-1));

				}
			}
			words.push_back(a);
			cin>>a;
		}
		n=e;
		getchar();
		getline(cin,s);
		int du;
		while(s.size()>0)
		{
			a=b=string();
			du=0;
			for(int i=0;i<s.size();i++)
				if(s[i]!=' ')
				{
					if(!du)
						a.push_back(s[i]);
					else
						b.push_back(s[i]);
				}
				else
					du=1;
			init();
			dijkstra(indices[a]);
			cout<<a<<" "<<b<<" "<<dist[indices[b]]<<endl;
			getline(cin,s);
		}	
	}
	
    return 0;
}