#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct shop
{
	int lev,dur,cost;
	shop(){}
	shop(int p_lev,int p_dur,int p_cost):lev(p_lev),dur(p_dur),cost(p_cost){}

	bool operator < (const shop &b) const
	{
		return (lev!=b.lev)?(lev<b.lev):(dur<b.dur);
	}
};

const int MAX = 1e5+2;
const ll INF = 1e14+2;

ll ft[MAX];
shop shops[MAX];
ll dp[MAX];
int n,s;

ll t[MAX * 2];

void build() 
{
	for(int i = n - 1; i > 0; i--)
		t[i] = min(t[i << 1] , t[i << 1 | 1]);
}

void update(int i, int val)
{
	for(t[i += n] = val; i >>= 1; )
		t[i] =min( t[i << 1] , t[i << 1 | 1]);
}
ll query(int l, int r)
{
	ll ans = INF;
	for(l+=n, r+=n; l <= r; l = (l+1) >> 1, r = (r-1) >> 1)
	{
		if(  l & 1 ) ans =min(ans, t[l]);
		if(!(r & 1)) ans =min(ans, t[r]);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int l,c;
	ll d;
	ft[0]=0;
	while(cin>>n>>s)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>ft[i];
			ft[i]+=ft[i-1];
		}
		ft[n+1]=ft[n];
		ft[n+2]=INF;
		for(int i=0;i<s;i++)
		{
			cin>>l>>d>>c;
			int lo=l, hi=n+1;
			while(lo<hi) 
			{
			  int mid = lo + (hi-lo+1)/2; 
			  if(d<ft[mid]-ft[l-1])
				hi = mid - 1;  
			  else
				lo = mid;
			}
			if(lo<n+1 && d>=ft[lo]-ft[l-1])
				lo++;
			shops[i]=shop(l,lo,c);
		}
		
		sort(shops,shops+s);
		n++;
		for(int i=1;i<n;i++)
			t[i+n]=INF;
		t[n+n]=0;
		t[n]=INF;
		build();
		ll ans;
		for(int i=s-1;i>=0;i--)
		{
			ans=min(INF,shops[i].cost+query(shops[i].lev,shops[i].dur));
			if(ans<t[shops[i].lev+n])
				update(shops[i].lev,ans);
		}	

		if(t[n+1]>=INF)
			cout<<-1<<endl;
		else
			cout<<t[n+1]<<endl;
		
	}
	return 0;
}