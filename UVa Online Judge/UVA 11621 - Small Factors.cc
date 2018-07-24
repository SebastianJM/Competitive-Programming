#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<long long> vec;
	long long res=1,ab,num;
	while(res<=2147483648)
	{
		vec.push_back(res);		
		res*=2;
	}
	res=3;
	while(res<=2147483648)
	{
		vec.push_back(res);
		res*=3;
	}
	ab=1;
	for(int i=1;i<29;i++)
	{
		ab*=2;
		res=ab;
		for(int e=1;e<30;e++)
		{
			res*=3;
			if(res<=2147483648)
				vec.push_back(res);
			else
				break;
		}
	}
	sort(vec.begin(),vec.end());
	while(1)
	{
		cin>>num;
		if(!num)
			return 0;
		int lo = 0, hi = vec.size() - 1;
		while(lo < hi) 
		{
			int mid = lo + (hi-lo)/2;
			if(vec[mid]>=num)
				hi = mid;  
			else
				lo = mid + 1;
		}
		cout<<vec[lo]<<endl;
	}
	return 0;
	
}