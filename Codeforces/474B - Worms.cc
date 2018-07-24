#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q,v[100005],ans[200005],a;
	cin>>n;
	int con=1;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		ans[i*2]=con;
		con+=v[i]-1;
		ans[i*2+1]=con++;
	}

	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>a;
		int lo=0,hi=n-1;
		while(lo<hi)
		{
			int mid=lo+(hi-lo+1)/2;
			if(ans[mid*2]>a)
				hi=mid-1;
			else
				lo=mid;
		}
		cout<<lo+1<<endl;
	}
	return 0;
}