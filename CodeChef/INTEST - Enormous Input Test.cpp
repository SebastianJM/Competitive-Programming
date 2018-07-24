#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,k,a,n=0;
	cin>>t>>k;
	while(t--)
	{
		cin>>a;
		if(a%k==0)
			n++;
		
	}
	cout<<n;
	return 0;
} 