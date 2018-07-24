#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii; 
typedef pair<int, ii> iii;

// Union-Find
vi pset;
void init(int n) 
{ pset = vi(n); for(int i = 0; i < n; i++) pset[i] = i; }
int findSet(int i) 
{ return (pset[i] == i)? i : (pset[i]= findSet(pset[i]));}
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

// Segunda iteración
bool prim;
// Kruskal
vector<iii> edges;
vector<bool> used;

ii mst(int n) 
{  
	int mstSize = 0; 
	long long mstCost = 0;  
	init(n);          
	for(int i=0;i<edges.size();i++)
	{
		iii edge = edges[i];
		int x = edge.second.first;  
		int y = edge.second.second; 
		int w = abs(edge.first);    
		if(!isSameSet(x, y)) 
		{  
			used[i]=true;
			unionSet(x, y); 
			mstSize++;      
			mstCost += w;  
		}
		else
			prim=false;	
		if(!prim && mstSize==n-1)
			break;
	}
	return ii(mstSize, mstCost); 
}

ii seg_mst(int n, int ign) 
{  
	int mstSize = 0; 
	long long mstCost = 0;  
	init(n);          
	for(int i=0;i<edges.size() && mstSize<n-1;i++)
	{
		if(i==ign)
			continue;
		iii edge = edges[i];
		int x = edge.second.first;  
		int y = edge.second.second; 
		int w = abs(edge.first);    
		if(!isSameSet(x, y)) 
		{  
			unionSet(x, y); 
			mstSize++;      
			mstCost += w;  
		}
	}
	return ii(mstSize, mstCost); 
}
int main() 
{
	int t,n,r,u,v,w,c=1;
	cin>>t;
	while(t--)
	{
		cin>>n>>r;
		edges=vector<iii>();
		used=vector<bool>(r,false);
		for(int i=0;i<r;i++)
		{
			cin>>u>>v>>w;
			u--;v--;
			edges.push_back(iii(w,ii(u,v)));
		}
		sort(edges.begin(),edges.end());
		prim=true;
		
		ii ans=mst(n);
		if(ans.first<n-1)
			cout<<"Case #"<<c++<<" : No way"<<endl;
		else
		{
			if(prim)
				cout<<"Case #"<<c++<<" : No second way"<<endl;
			else
			{
				int ans=(1<<30);
				for(int i=0;i<r;i++)
					if(used[i])
					{
						ii ax=seg_mst(n,i);
						if(ax.first==n-1)
							ans=min(ans,seg_mst(n,i).second);
					}
				cout<<"Case #"<<c++<<" : "<<ans<<endl;
			}
		}
	}
	
	return 0;
}