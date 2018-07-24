#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int ar[2000000];
	while(1)
	{
		cin>>n;
		if(!n)
			break;
		for(int i=0;i<n;i++)
			cin>>ar[i];
		sort(ar,ar+n);
		cout<<ar[0];
		for(int i=1;i<n;i++)
			cout<<" "<<ar[i];
		cout<<"\n";
	}
	
	return 0;
}