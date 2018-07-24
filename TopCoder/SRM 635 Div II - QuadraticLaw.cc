#include <bits/stdc++.h>

using namespace std;

class QuadraticLaw
{
	public:
		long long getTime(long long d)
		{
			long long lo = 0, hi = 1e18;
			while(lo < hi)
			{
				long long mid = lo + (hi-lo+1)/2; 		
				if((double)(1+mid)>(double)(d/mid))
					hi = mid - 1; 
				else 
					lo = mid; 
			}
			return lo;
		}
};
