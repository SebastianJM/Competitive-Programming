#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii; // Pair : (Node, Node)
typedef pair<unsigned long long, unsigned long long> llll;
typedef pair<ii,int> ii_i;
typedef pair<llll, ii_i > iii; // Triple : (Weight, (Node, Node))
// Union-Find
vi pset;
bool is[30005];
void initSet(int n) 
{ 
	pset = vi(n); 
	for(int i = 0; i < n; i++) 
		pset[i] = i; 
}
int findSet(int i) 
{ 
	return (pset[i] == i)? i : (pset[i]= findSet(pset[i]));
}
void unionSet(int i, int j) 
{ 
	pset[findSet(i)] = findSet(j); 
}
bool isSameSet(int i, int j) 
{ 
	return findSet(i) == findSet(j); 
}
// Kruskal
priority_queue<iii> edges; // List of edges
unsigned long long mst(int n) // n: Number of nodes
{
	int mstSize = 0; // mst_size: Number of edges of the MST
	unsigned long long mstCost = 0; // mst_cost: Weight of the MST
	initSet(n); // Initialize Union-Find
	while(!edges.empty() && mstSize < n - 1) // If there are edges..
	{
		iii edge = edges.top(); 
		edges.pop(); // Get the lowest-cost edge
		int x = edge.second.first.first, y = edge.second.first.second; // Get nodes
		unsigned long long w = edge.first.second; // Get weight
		if(!isSameSet(x,y)) // If the nodes are not in the same CC..
		{
			unionSet(x,y); // Connect the nodes
			is[edge.second.second]=true;
		
			mstSize++; // The tree gains one edge
			mstCost += w; // The weight of the tree increases
		}
	}
	return mstCost; // Returns: (Number of edges on MST, Weight)
}
int main() 
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,a,b,e=0,x,y;
	unsigned long long r,c;
	map<int,int> mp;
	memset(is,false,sizeof is);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>r>>c;
		if(mp.find(a)!=mp.end())
			x=mp[a];
		else
		{
			x=e;
			mp[a]=e++;
		}
		if(mp.find(b)!=mp.end())
			y=mp[b];
		else
		{
			y=e;
			mp[b]=e++;
		}
		edges.push(iii(ii(r,c),ii_i(ii(x,y),i)));
	}

	unsigned long long ans = mst(e); 
	cout<<ans<<endl;
	bool fir=true;
	for(int i=0;i<n;i++)
		if(!is[i])
		{
			if(!fir)
				cout<<" ";
			fir=false;
			cout<<i+1;
		}
	for(int i=0;i<n;i++)
		if(is[i])
		{
			if(!fir)
				cout<<" ";
			fir=false;
			cout<<i+1;
		}
	cout<<endl;
	return 0;
}