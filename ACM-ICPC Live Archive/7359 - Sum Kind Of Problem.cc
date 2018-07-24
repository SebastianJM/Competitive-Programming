#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,q,n;
	cin>>t;
	while(t--)
	{
		cin>>q>>n;
		cout<<q<<" "<<n*(n+1)/2<<" "<<n*n<<" "<<n*(n+1)<<endl;
	}
	return 0;
}