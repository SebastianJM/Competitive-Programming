#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

int n,go,ho,k;
double dist[105][105];
map<double,int> dif_dist;
vector<double> unique_dif_dist;
	
vvi g;
vi match; 
vb visit; 

struct gopher
{
  double x,y;
  gopher(){}
  gopher(double px,double py):x(px),y(py){}
};

gopher v[105];

int augmenting(int v) 
{
    if(visit[v]) 
        return 0;  
    visit[v] = true;
    for(int i = 0; i < (int)g[v].size(); i++) 
    {
        int u = g[v][i];
 
        if(match[u] == -1 || augmenting(match[u]))
        {
            match[u] = v; 
            return 1;    
        }
    }
    return 0; 
}

int MCBM(int left) 
{
    int ans = 0;       
    match = vi(n, -1);
    for(int i = 0; i < left; i++) 
    {
        visit = vb(left, false); 
        ans += augmenting(i);  
    }
    return ans;
}

int solve(double d)
{
	g=vvi(n);
	for(int i=0;i<go;i++)
		for(int e=0;e<ho;e++)
			if(dist[i][e]<=d)
			{
				g[i].push_back(e+go);
				g[e+go].push_back(i);
			}
	
	return MCBM(go);
}
int main() 
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	int t,q=1;
	double x,y;
	
	cin>>t;
	while(t--)
	{

	    cin>>go>>ho>>k;
	    n=go+ho;
	    dif_dist.clear();
	    unique_dif_dist=vector<double>();
	    for(int i=0;i<go;i++)
	        cin>>v[i].x>>v[i].y;
	    for(int i=0;i<ho;i++)
	    {
	        cin>>x>>y;
	        for(int e=0;e<go;e++)
	        {
	            dist[e][i]=hypot(v[e].x-x,v[e].y-y);
	            dif_dist[dist[e][i]]++;
	        }
	    }
	    for(map<double,int>::iterator it=dif_dist.begin();it!=dif_dist.end();it++)
	    	unique_dif_dist.push_back(it->first);
		cout<<"Case #"<<q++<<":"<<endl;
		
	    if(go-k>ho)
	    {
	    	
	    	cout<<"Too bad."<<endl;
	    	cout<<endl;
	    	continue;
	    }
		if(go==0 || (ho == 0 && go<=k))
		{
			cout<<"0.000"<<endl;
			cout<<endl;
			continue;
		}
		int lo = 0, hi = unique_dif_dist.size()-1;
		while(lo < hi) 
		{
			int mid = lo + (hi-lo)/2;
			if(solve(unique_dif_dist[mid])>=go-k)
				hi = mid;  
			else
				lo = mid + 1;
		}
		printf("%.3lf\n",unique_dif_dist[lo]);
	    cout<<endl;
	}
	return 0;
}