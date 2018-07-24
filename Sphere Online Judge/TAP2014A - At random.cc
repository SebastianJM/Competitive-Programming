#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n,t,a1,a2;
	bool ans;
	char c1,c2;
	cin>>t;
	while(t--)
	{
		cin>>n>>a2>>c2;
		ans=true;
		for(int i=0;i<n-1;i++)
		{
			cin>>a1>>c1;
			if(a1==a2 || c1==c2)
				ans=false;
			a2=a1;c2=c1;
		}
		if(ans)
			cout<<"B\n";
		else
			cout<<"M\n";
	}
	return 0;
} 