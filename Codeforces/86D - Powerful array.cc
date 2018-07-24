#include <bits/stdc++.h>
using namespace std;

#define N 300000
#define A 1003000
#define BLOCK 547 // ~sqrt(N)

unsigned long long cnt[A], a[N], ans[N],answer=0,aux;

struct node 
{
	int L, R, i;
	node(){}
};

node q[N];

bool cmp(node x, node y) 
{
	if(x.L/BLOCK != y.L/BLOCK) 
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	
	// same block, so sort by R value
	return x.R < y.R;
}

inline void add(int position) 
{
	answer += 2 * cnt[a[position]] * a[position] + a[position];
	cnt[a[position]]++;	
}

inline void remove(int position)
{
	cnt[a[position]]--;
	answer -= 2 * cnt[a[position]] * a[position] + a[position];
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>a[i];

	for(int i=0; i<m; i++) 
	{
		cin>>q[i].L>>q[i].R;
		q[i].L--; q[i].R--;
		q[i].i = i;
	}

	sort(q, q + m, cmp);

	int currentL = 0, currentR = 0,L,R;
	for(int i=0; i<m; i++) 
	{
		L = q[i].L, R = q[i].R;
		while(currentL < L) 
			remove(currentL++);
			
		while(currentL > L) 
			add(--currentL);

		while(currentR <= R) 
			add(currentR++);

		while(currentR > R+1) 
			remove(--currentR);

		ans[q[i].i] = answer;
	}

	for(int i=0; i<m; i++)
		cout<<ans[i]<<"\n";
}