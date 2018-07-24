#include <bits/stdc++.h>
using namespace std;

int main()
{
	int per,n;
	while(cin>>per)
	{
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		int lo,hi,mid,popeAux,pope1,pope2,can=0;
		for(int i=0;i<=n-per+1;i++)
		{
			lo=0,hi=n-1;
			while(lo<hi)
			{
				mid=lo+(hi-lo+1)/2;
				if(vec[mid]>vec[i]+per-1)
					hi=mid-1;
				else
					lo=mid;
			}
			if(lo-i>can)
			{
				can=lo-i;
				pope1=vec[i];
				pope2=vec[lo];
			}
		}
		cout<<can+1<<" "<<pope1<<" "<<pope2<<endl;
	}
	return 0;
}