#include <bits/stdc++.h>
using namespace std;
 
#define MAX 2000004
#define NMAX 1000004
int v[MAX];
long long pref[MAX],ans[NMAX];
 
long long dp(int x)
{
	if(ans[x]>=0)
		return ans[x];
	return ans[x]=dp(x-1)+2*(pref[2*x]-pref[x])-v[2*x];
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,n,par,inp,c;
	
	for(int i=2;i<MAX;i++)
	{
		par=inp=0;
		n=i;
		while(n)
		{
			t=n%10;
			if(t&1)
				inp+=t;
			else
				par+=t;
			n/=10;
		}
		v[i]=abs(par-inp);
	}
	pref[0]=ans[0]=0;
	pref[1]=0;
	pref[2]=2;
	for(int i=3;i<MAX;i++)
		pref[i]+=pref[i-1]+v[i];
	
	memset(ans,-1,sizeof ans);
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<dp(n)<<"\n";
	}
	return 0;
}  