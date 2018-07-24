#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n,v[100005];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v,v+n);
	for(int i=2;i<n;i++)
		if(v[i-2]+v[i-1] > v[i])
		{
			cout<<"YES"<<endl;
			return 0;
		}
	cout<<"NO"<<endl;
	return 0;
}