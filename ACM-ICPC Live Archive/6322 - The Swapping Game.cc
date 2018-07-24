#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
 
#define MAX_V 206 
#define INF 1000000000
 
int res[MAX_V][MAX_V], ori[MAX_V][MAX_V], f, s, t;      
vi p;
 
void augment(int v, int minEdge) 
{     
	if (v == s) 
	{ 
		f = minEdge; 
		return; 
	}  
	else if (p[v] != -1) 
	{ 
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f; 
	}  
}
int flow()
{
	int mf=0;                                       
	while (1) 
	{              // O(VE^2) (actually O(V^3E) Edmonds Karp's algorithm
		f = 0;
		vi dist(MAX_V, INF); dist[s] = 0; queue<int> q; q.push(s);
		p.assign(MAX_V, -1);         
		while (!q.empty()) 
		{
			int u = q.front(); 
			q.pop();
			if (u == t) 
				break;     
			for (int v = 0; v < MAX_V; v++)  
				if (res[u][v] > 0 && dist[v] == INF)
					dist[v] = dist[u] + 1, q.push(v), p[v] = u;
		}
		augment(t, INF);  
		if (f == 0) break;   
		mf += f;   
	}
	return mf;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int caso,V, k,n,expect;
  bool is;
  vector<char> ans;
  string a,b,c;
   vector<int> letras[26];
  cin>>caso;
 
  while(caso--)
  {
	  s=0;
	  t=204;
	  cin>>a;
 		n=a.size();
	  for(int i=0;i<26;i++)
	  	letras[i].clear();
	  b=a;
	  sort(b.begin(),b.end());
	  for(int i=0;i<n;i++)
	  {
	  	letras[b[i]-'a'].push_back(i);
	  }
	  memset(res, 0, sizeof res);
	  memset(ori, 0, sizeof ori);
	  for(int i=0;i<n;i++)
	  	res[0][i+1]=ori[0][i+1]=1;
	  for(int i=0;i<n;i++)
	  {
	  	cin>>c;
	  	for(int j=0;j<c.size();j++)
	  		for(int k=0;k<letras[c[j]-'a'].size();k++)
	  		{
	  			res[i+1][102+letras[c[j]-'a'][k]]=ori[i+1][102+letras[c[j]-'a'][k]]=1;
	  		}
	  }
	  for(int i=0;i<n;i++)
	  	res[102+i][204]=ori[102+i][204]=1;
	  
 		int flujo=flow();

 	
	  if(flujo<n)
	  	cout<<"NO SOLUTION\n";
	  else
	  {
	  	ans=vector<char>(n);
		for(int x=0;x<MAX_V;x++)
  			for(int y=0;y<MAX_V;y++)
  				res[x][y]=ori[x][y];
	  	expect=n-1;
	  	for(int i=1;i<=n;i++)
	  	{
	  		is=false;
		  	for(int j=102;j<102+n;j++)
		  	{
		  		if(res[i][j]>0)
		  		{
		  			
		  			for(int x=1;x<=n;x++)
		  				res[x][j]=0;
		  			res[0][i]=0;
		  			flujo=flow();
		  	
		  			if(flujo==expect)
		  			{
		  				expect--;
		  				ans[i-1]=b[j-102];
			  			for(int x=1;x<=n;x++)
		  					ori[x][j]=0;
		  				ori[0][i]=0;
			  			is=true;
		  			}
	  				for(int x=0;x<MAX_V;x++)
		  				for(int y=0;y<MAX_V;y++)
		  					res[x][y]=ori[x][y];
		  		}
		  		if(is)
		  		break;
		  	}
		  		
		  	}
		 for(int i=0;i<n;i++)
		 	cout<<ans[i];
		 cout<<"\n";
	  }
 
  }
  return 0;
}