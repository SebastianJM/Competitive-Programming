#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll v[100005],ar[100005];
ll maxSum1D(int x,int y)
{
	ll sum = 0,maxsum = -1;
	for(int i = x; i < y; i++)
	{
		sum = sum + ar[i];
		if(sum > maxsum) { maxsum = sum;} // [ki, y]
		if(sum < 0) { sum = 0;} // Si es negativo, actualizar ki
	}
	return maxsum;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll maxi=0;;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>v[i];
	for(int i=0;i<n-1;i++)
		ar[i]=labs(v[i]-v[i+1])*(i&1?-1LL:1LL);
	ll ans=maxSum1D(0,n-1);
	for(int i=1;i<n-1;i++)
		ar[i]=labs(v[i]-v[i+1])*(i&1?1LL:-1LL);
	ans=max(ans,maxSum1D(1,n-1));
	cout<<ans<<endl;
	return 0;
}