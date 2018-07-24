#include <bits/stdc++.h>
using namespace std;

int v[1002];
int main() 
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>v[i];
		int ans=(1<<30),aux;
		aux=0;
		sort(v,v+n);
		for(int i=1;i<n;i+=2)
			aux+=min(abs(v[i]-v[i-1]),24-abs(v[i]-v[i-1]));
		ans=min(ans,aux);
		aux=0;
		if(n>2)
		{
			for(int i=2;i<n;i+=2)
				aux+=min(abs(v[i]-v[i-1]),24-abs(v[i]-v[i-1]));
			aux+=min(abs(v[0]-v[n-1]),24-abs(v[0]-v[n-1]));
			ans=min(ans,aux);
		}
		cout<<ans<<endl;
	}
	return 0;
}