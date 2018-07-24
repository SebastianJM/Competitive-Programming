#include <bits/stdc++.h>

using namespace std;

struct node
{
	int ind;
	unsigned long long val;
	node(){}
	bool operator < (const node& b) const
	{
		if(val==b.val)
			return ind>b.ind;
		return val>b.val;
	}
};

node v[1000006];
unsigned long long ac[1000006];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,n,a;

	cin>>t;
	while(t--)
	{
		cin>>n;
		ac[0]=0;
		v[0].ind=0,v[0].val=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			v[i].ind=i;
			v[i].val=a;
			ac[i]=a+ac[i-1];
		}
		sort(v,v+n+1);
		int last=v[0].ind,ant=1,i=0;
		unsigned long long ans=0;
		while(last!=n)
		{		//ans+=m[last]*(last-ant)-(ac[last-1]-ac[ant]+m[ant]);
			if(last>ant)
				ans+=(ac[last]-ac[last-1])*(last-ant)-(ac[last-1]-ac[ant-1]);
			while(last>=v[i].ind)
				i++;
			ant=last+1;
			last=v[i].ind;
		}
		if(last>ant)
			ans+=(ac[last]-ac[last-1])*(last-ant)-(ac[last-1]-ac[ant-1]);
		cout<<ans<<endl;
	}
	return 0;
}