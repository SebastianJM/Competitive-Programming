#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
	int v[10];
	int n,a;
	cin>>n;
	while(n--)
	{
		cin>>a;
		for(int i=0;i<10;i++)
			cin>>v[i];
		sort(v,v+10,greater<int>());
		cout<<a<<" "<<v[2]<<endl;
	}
	return 0;
}