#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef tuple<int,int,int,int> iii;
typedef vector<iii> viii;

const int MAX = 1e5; // Max number of elements
int t[MAX*2]; // Segment Tree (Root is t[1])
int n; // Number of elements of the array

inline void build() // Builds the segment tree
{
	for(int i = n - 1; i > 0; i--) // For each non-leaf node..
		t[i] = t[i << 1] + t[i << 1 | 1]; // Update according to both children
}
inline void update(int i, int val) // Sets array[i] to val (i in range [0, N-1])
{
	for(t[i += n] = val; i >>= 1; ) // Update leaf node, then go up..
		t[i] = t[i << 1] + t[i << 1 | 1]; // Update according to children
}
inline int query_st(int l, int r) // Range Sum Query in range [l,r]
{
	int ans = 0;
	for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
	{
		if( l & 1 ) ans = ans + t[l]; // For left pointer, odd nodes matter
		if(!(r & 1)) ans = t[r] + ans; // For right pointer, even nodes matter
	}
	return ans;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q,u,v,k;
	cin>>n;
	int ans[200003];
	ii par[30003];
	iii query[200003];
	for(int i=n;i<2*n;i++)
	{
		cin>>par[i-n].first;
		par[i-n].second=i-n;
		t[i]=1;
	}
	build();
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>u>>v>>k;
		query[i]=iii(k,u,v,i);
	}
	sort(par,par+n);
	sort(query,query+q);
	for(int i=0,e=0;i<q;i++)
	{
		while(e<n && par[e].first<=get<0>(query[i]))
		{
			update(par[e].second,0);
			e++;
		}

		ans[get<3>(query[i])]=query_st(get<1>(query[i])-1,get<2>(query[i])-1);
		
	}

	for(int i=0;i<q;i++)
		cout<<ans[i]<<"\n";
	return 0;
}