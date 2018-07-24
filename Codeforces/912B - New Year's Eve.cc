#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define MAX 1000005
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main() 
{
	fastIO;
	ull n,k,ans;
	int maxi=0;
	cin>>n>>k;
	ans=n;
	//n=INT_MAX;
	for(int i=0;i<70 && n;i++)
	{
		ull x=1;
		//cout<<((n&(x<<i))?1:0);
		if(n&(x<<i))
		{
			n^=(x<<i);
			maxi=max(maxi,i);
		}
	}
/*	cout<<endl;
	cout<<n<<endl;	
	cout<<ULLONG_MAX<<endl;*/
	ull e,x=1;
	int i;

		if(k>1)
		{
			ans=0;
			for(i=maxi;i>=0;i--)
			{
				ans|=(x<<i);	
			}	
		}
			
	
	
		
	cout<<ans<<endl;
		
	return 0;
}