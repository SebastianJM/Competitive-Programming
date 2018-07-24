#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin>>n)
	{
		if(!n)
			break;
		cout<<1;
		for(int i=2;i<=n;i++)
		{
			if(i*i<=n)
				cout<<" "<<i*i;
			else
				break;
		}
		cout<<endl;
	}
	return 0;
}