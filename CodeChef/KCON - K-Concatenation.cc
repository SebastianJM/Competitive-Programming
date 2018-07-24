#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
#define MAX 100006
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll v[MAX];
int n;
ll kadane()
{
	ll ans=0,con=0;
	for(int i=0;i<n;i++)
	{
		con+=v[i];
		if(con<0)
			con=0;
		else
			ans=max(ans,con);
	}
	return ans;
}
ll right()
{
	ll ans=0,con=0;;
	for(int i=0;i<n;i++)
	{
		con+=v[i];
		ans=max(ans,con);
	}
	return ans;
}
ll left()
{
	ll ans=0,con=0;;
	for(int i=n-1;i>=0;i--)
	{
		con+=v[i];
		ans=max(ans,con);
	}
	return ans;
}
int main() 
{
	fastIO;
	int t,k;
	ll max_el;
	
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		ll con=0;
		max_el=-10000000000;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			max_el=max(max_el,v[i]);
			con+=v[i];
		}
		if(max_el>0)
		{
			ll ans=kadane();
			ll l=left(),r=right();
			ans=max(ans,con*k);
			if(k>=1)
			{
				ans=max(ans,con*(k-1)+l);
				ans=max(ans,con*(k-1)+r);
			}
			if(k>=2)
			{
				ans=max(ans,l+r+con*(k-2));
				ans=max(ans,l+r);
			}
			cout<<ans<<endl;
		}
		else
			cout<<max_el<<endl;
 
 
		
		
		
	}
	
	return 0;
} 