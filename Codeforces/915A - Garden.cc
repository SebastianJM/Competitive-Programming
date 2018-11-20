#include <bits/stdc++.h>

using namespace std;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 10001050


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ull> vull;
int main() 
{
	fastIO;
	int n,k,a;
	cin>>n>>k;
	int ans=MAX;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(k%a==0)
		{
			ans=min(ans,k/a);
		}
	}
	cout<<ans<<endl;
	return 0;
} 