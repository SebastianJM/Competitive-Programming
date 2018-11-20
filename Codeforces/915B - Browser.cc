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
	int n,pos,l,r,ans=0;
	cin>>n>>pos>>l>>r;
	
	if(pos<l)
	{

		ans+=l-pos;
		ans++;
		if(r!=n)
		{
			ans+=r-l;
			ans++;
		}
	}
	else if(pos>r)
	{
		ans+=pos-r;
		
		ans++;
		if(l!=1)
		{
			ans+=r-l;
			ans++;
		}
	}
	else
	{
		if(l==1 && r==n)
		{
			ans=0;
		}
		else if(l!=1 && r==n)
		{
			ans+=pos-l;
			ans++;
		}
		else if(l==1 && r!=n)
		{
			ans+=r-pos;
			ans++;
		}
		else
		{
			ans+=min(pos-l,r-pos);
			ans+=r-l;
			ans+=2;
		}
	}
	cout<<ans<<endl;
	return 0;
} 