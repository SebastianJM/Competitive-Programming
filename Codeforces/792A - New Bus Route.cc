
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,v[200004],a,b;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v,v+n);
	a=v[1]-v[0];
	b=1;
	for(int i=2;i<n;i++)
	{
		if(v[i]-v[i-1]<a) a=v[i]-v[i-1],b=1;
		else if(v[i]-v[i-1]==a)	b++;
	}
	cout<<a<<" "<<b<<"\n";
	return 0;
}