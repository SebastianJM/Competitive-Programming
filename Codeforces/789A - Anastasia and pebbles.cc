#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n,k,v,ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>v;
		ans+=(int)(ceil((double)(v)/(double)(k)));
		//cout<<ans<<endl;
	}
	cout<<(int)(ceil((double)(ans)/2.0))<<endl;
	return 0;
}