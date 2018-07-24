#include <bits/stdc++.h>

using namespace std;

int findSurvivor(int n, int k) // n personas, se elimina cada k personas
{
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = (ans + k) % i;
	return ans+1; // (+1 si la numeración de las personas comenzara en 1)
}

int main()
{
	int t,n,k,q=0;
	cin>>t;
	while(q++!=t)
	{
		cin>>n>>k;
		cout<<"Case "<<q<<": "<<findSurvivor(n,k)<<endl;
	}
	return 0;
}