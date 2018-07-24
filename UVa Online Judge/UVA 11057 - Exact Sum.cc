#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,total,res,pri=1;
	//freopen ("out.txt","w",stdout);
	while(cin>>n)
	{
		vector<int> vec(n);
		vector<bool> visi(n,false);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		sort(vec.begin(),vec.end());
		cin>>total;
		int p1,p2,lo=0,hi=n-1;
		while(lo<hi)
		{
			if(vec[lo]+vec[hi]<total)
				lo++;
			else if(vec[lo]+vec[hi]==total)
			{
				p1=lo;
				p2=hi;
				lo++;
			}
			else
				hi--;
		}
				
		cout<<"Peter should buy books whose prices are "<<vec[p1]<<" and "<<vec[p2]<<"."<<endl;
		
		cout<<endl;
	}
	return 0;
	
}
