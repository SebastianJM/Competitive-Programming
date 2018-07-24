#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ull> vi;
typedef vector<vi> vvi;
 
#define MAX 703
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main() 
{
	fastIO;
	int t,n;
	vvi m;
	cin>>t;
	while(t--)
	{
		cin>>n;
		m=vvi(n,vi(n));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			
				cin>>m[i][j];
			
		for(int i=0;i<n;i++)
			sort(m[i].begin(),m[i].end());
		bool is=true;
		
		ull last=m[n-1][n-1];
		ull ans=last;
		//cout<<last<<endl;
		for(int f=n-2;f>=0;f--)
		{
			int pos=lower_bound(m[f].begin(),m[f].end(),last)-m[f].begin();
			if(pos>=n)
				pos--;
			if(m[f][pos]>=last)
				pos--;
			if(m[f][pos]>=last)
			{
				is=false;
				break;
			}
			else
			{
				last=m[f][pos];
				//cout<<pos<<" "<<last<<endl;
				ans+=last;
			}
		}
		if(is)
			cout<<ans<<endl;
		else
			cout<<-1<<endl;
			
	}
	return 0;
}
 