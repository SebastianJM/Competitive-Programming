#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vi;
#define N 20010
#define A 20010
#define BLOCK 141 // ~sqrt(N)
#define LSOne(S) (S & (-S)) // Least Significant One

vi t;
int n;
long long a[N],ta[N], ans[N],answer=0;

struct node 
{
	int L, R, i;
	node(){}
};

inline void inc(int i, long long val)
{
	for(i++; i <= n; i += LSOne(i))
		t[i] += val;
}
inline long long rsq(int i)
{
	long long sum = 0;
	for(i++; i; i -= LSOne(i))
		sum += t[i];
	return sum;
}
inline long long rsq(int l, int r)
{
	return rsq(r) - rsq(l - 1);
}

bool cmp(node x, node y) 
{
	if(x.L/BLOCK != y.L/BLOCK) 
		return x.L/BLOCK < y.L/BLOCK;
	return x.R < y.R;
}

inline void add(int position,int type) 
{
    inc(a[position],1);
	answer += (type?rsq(0,a[position]-1):rsq(a[position]+1,n-1));
}

inline void remove(int position,int type)
{
	inc(a[position],-1);
	answer-=(type?rsq(0,a[position]-1):rsq(a[position]+1,n-1));
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int m;
	node q[N];
	
	cin>>n;
	t = vi(n + 1, 0);
	for(int i=0; i<n; i++)
	{
		cin>>ta[i];
		a[i]=ta[i];
	}
	sort(ta,ta+n);
	int cnt=int(unique(ta,ta+n)-ta);

	for(int i=0; i<n; i++)
		a[i]=int(lower_bound(ta,ta+cnt,a[i])-ta);

	cin>>m;
	
	for(int i=0; i<m; i++) 
	{
		cin>>q[i].L>>q[i].R;
		q[i].L--; q[i].R--;
		q[i].i = i;
	}

	sort(q, q + m, cmp);

	int currentL = q[0].L, currentR = q[0].L,L,R;
	for(int i=0; i<m; i++) 
	{
		L = q[i].L, R = q[i].R;
		while(currentL < L) 
			remove(currentL++,1);
			
		while(currentL > L) 
			add(--currentL,1);

		while(currentR <= R) 
			add(currentR++,0);

		while(currentR > R+1) 
			remove(--currentR,0);

		ans[q[i].i] = answer;
	}

	for(int i=0; i<m; i++)
		cout<<ans[i]<<"\n";
}