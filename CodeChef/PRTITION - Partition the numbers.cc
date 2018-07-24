#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000105
typedef vector<int> vi;
typedef unsigned long long ull;
ull n,k,meta;
int ans[MAX];
 
int main() 
{
	fastIO;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>k>>n;
		meta=n*(n+1ULL)/2ULL-k;
		
		if(meta&1ULL)
			cout<<"impossible\n";
		else
		{
			meta/=2ULL;
			memset(ans,0,sizeof ans);
			ans[k]=2;
			ull a=0ULL;
			for(ull i=n;i>=1ULL;i--)
			{
				if(i!=k && a+i<=meta)
				{
					a+=i;
					//cout<<"IN "<<i<<endl;
					ans[i]=1;
				}
			}
			if(a==meta)
			{
				
				for(ull i=1;i<=n;i++)
					cout<<ans[i];
				cout<<"\n";
			}
			else
			{
				memset(ans,0,sizeof ans);
				ans[k]=2;
				ull b=0ULL;
				for(ull i=n-1;i>=1ULL;i--)
				{
					if(i!=k && b+i<=meta)
					{
						b+=i;
						//cout<<"IN "<<i<<endl;
						ans[i]=1;
					}
				}
				if(b==meta)
				{
					
					for(ull i=1;i<=n;i++)
						cout<<ans[i];
					cout<<"\n";
				}
				else
				cout<<"impossible\n";
			}
				
		}
		
	}
	return 0;
} 