// SIN SEGMENT TREES  (0.310 s)
#include <bits/stdc++.h>
using namespace std;

#define MAX 200002
#define N 100003
#define DELTA 100000
#define BLOCK 447

int  cnt[MAX],freq[N],a[N], ans[N],answer;

struct node 
{
	int L, R, i;
	node(){}
};

node q[N];

bool cmp(node x, node y) 
{
	if(x.L/BLOCK != y.L/BLOCK) 
		return x.L/BLOCK < y.L/BLOCK;
	return x.R < y.R;
}
	
void add(int position) 
{
	freq[cnt[a[position]]]--;
	cnt[a[position]]++;
	freq[cnt[a[position]]]++;
	answer=max(answer,cnt[a[position]]);
}

void remove(int position)
{
	freq[cnt[a[position]]]--;
	if(cnt[a[position]]==answer && freq[cnt[a[position]]]==0)
		answer--;
	cnt[a[position]]--;
	freq[cnt[a[position]]]++;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		cin>>m;
		answer=0;
		memset(cnt,0,sizeof cnt);
		memset(freq,0,sizeof freq);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			a[i]+=DELTA;
		}
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
	return 0;
}



// CON SEGMENT TREES (2.880 s)
#include <bits/stdc++.h>
using namespace std;

const int MAX = 2*(1e5)+4; 
const int DELTA = 100000;
int t[MAX*2];
int n;

#define N DELTA+4
#define BLOCK 447

int  a[N], ans[N];

struct node 
{
	int L, R, i;
	node(){}
};

node q[N];

bool cmp(node x, node y) 
{
	if(x.L/BLOCK != y.L/BLOCK) 
		return x.L/BLOCK < y.L/BLOCK;
	return x.R < y.R;
}

void update(int i, int val)
{
	for(t[i += n] += val; i >>= 1; )
		t[i] = max(t[i << 1] , t[i << 1 | 1]); 
}
int query(int l, int r) 
{
	int ans = 0;
	for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
	{
		if( l & 1 ) ans = max(ans , t[l]); 
		if(!(r & 1)) ans = max(t[r], ans); 
	}
	return ans;
}
void add(int position) 
{
	update(a[position],1);
}

void remove(int position)
{
	update(a[position],-1);
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m;
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		cin>>m;
		memset(t,0,sizeof t);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			a[i]+=DELTA;
		}
		for(int i=0; i<m; i++) 
		{
			cin>>q[i].L>>q[i].R;
			q[i].L--; q[i].R--;
			q[i].i = i;
		}
	
		sort(q, q + m, cmp);
		n=DELTA*2;
		
		int currentL = q[0].L, currentR = q[0].L,L,R;
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

			ans[q[i].i] = query(0,MAX-2);
		}
	
		for(int i=0; i<m; i++)
			cout<<ans[i]<<"\n";
	}
	return 0;
}