#include <bits/stdc++.h>
using namespace std;

#define N 100004
#define A 100004
#define BLOCK 316 // ~sqrt(N)

int cnt[A], a[N], ta[N], real_val[N], ans[N], answer=0;

struct node 
{
	int L, R, i, block;
	node(){}
};
node q[N];
bool cmp(const node &x, const node &y) 
{
	if(x.block != y.block) 
		return x.block < y.block;
	return x.R < y.R;
}

void add(int position) 
{
	cnt[a[position]]++;
	if(cnt[a[position]] == real_val[a[position]]) 
		answer++;
	else if(cnt[a[position]] == real_val[a[position]]+1)
		answer--;
}
void remove(int position)
{
	cnt[a[position]]--;
	if(cnt[a[position]] +1 == real_val[a[position]]) 
		answer--;
	if(cnt[a[position]] == real_val[a[position]]) 
		answer++;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m,u=0,op;
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
	{
		cin>>ta[i];
		a[i]=ta[i];
	}
	
	sort(ta,ta+n);
	int cnt=int(unique(ta,ta+n)-ta);
	for(int i=0; i<n; i++)
	{
		op=int(lower_bound(ta,ta+cnt,a[i])-ta);
		real_val[op]=a[i];
		a[i]=op;
	}

	for(int i=0; i<m; i++) 
	{
		cin>>q[i].L>>q[i].R;
		q[i].L--; q[i].R--;
		q[i].i = i;
		q[i].block=q[i].L/BLOCK;
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
