#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
int main() {
	int n,a[MAX];
	bool cumple[MAX];
	memset(cumple,false,sizeof cumple);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cumple[n]=true;
	for(int i=n-1;i>=0;i--)
	{
		if(i+a[i]+1<=n+1 && cumple[i+a[i]+1])
			cumple[i]=true;
	}
	for(int i=1;i<n;i++)
		if(cumple[i])
			cout<<i<<"\n";
	cout<<n<<"\n";
	return 0;
} 