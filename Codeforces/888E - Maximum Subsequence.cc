#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,k,z;
	vi x,y;
	cin>>n>>k;
	int mid=n/2;
	for(int i=0;i<mid;i++)
	{
		cin>>z;
		x.push_back(z);
	}
	for(int i=mid;i<n;i++)
	{
		cin>>z;
		y.push_back(z);
	}
		
	vi a,b;
	long long up;
	for(int i=0;i<(1<<x.size());i++)
	{
		up=0;
		for(int j=0;j<x.size();j++)
			if(i&(1<<j))
				up+=x[j];
		a.push_back(up%k);
	}
	for(int i=0;i<(1<<y.size());i++)
	{
		up=0;
		for(int j=0;j<y.size();j++)
			if(i&(1<<j))
				up+=y[j];
		b.push_back(up%k);
	}
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int ans=max(a[a.size()-1],b[b.size()-1]);
	if(ans!=k-1)
	{
		vi::iterator it;
		int lo,hi;
		for(int i=0;i<a.size();i++)
		{
			lo=0;
			hi=b.size()-1;
			while(lo < hi)
			{
				mid = lo + (hi-lo)/2; // Find middle element (ROUNDED DOWN)
				if(a[i]+b[mid]>=k) // If mid satisfies the property..
					hi = mid; // Search in: [lo, mid], we are minimizing the value
				else // Else if mid does not satisfy the property..
					lo = mid + 1; // Search in: [mid+1, hi], we want a value that satisfies
			}
			if(lo>0)
				ans=max(ans,a[i]+b[lo-1]);
			ans=max(ans,(a[i]+b[b.size()-1])%k);
		}
	}
	cout<<ans<<endl;
	return 0;
}