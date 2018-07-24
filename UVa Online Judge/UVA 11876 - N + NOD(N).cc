#include <bits/stdc++.h>

using namespace std;

vector<int> N;

int divisors(int M){
	int i;
	int cnt = 0;
	for( i=1; i*i < M; i++ )
		if( M % i == 0 )
			cnt += 2;
	if( i * i == M )
		cnt++;
	return cnt;
}

int main()
{
	N.push_back(1);
	int e=0,a,b,square_root,t;
	while(N[e]<1000000)
	{
		e++;	
		N.push_back(N[e-1]+divisors(N[e-1]));
	}
	cin>>t;
	e=1;
	while(t--)
	{
		cin>>a>>b;
		int lo = 0, hi = N.size() - 1;
		while(lo < hi) 
		{
			int mid = lo + (hi-lo)/2;
			if(N[mid]>=a)
				hi = mid;  
			else
				lo = mid + 1;
		}
		a=lo;
		lo=0;
		hi=N.size()-1;
		while(lo < hi) 
		{
			int mid = lo + (hi-lo+1)/2; 
			if(N[mid]>b)
				hi = mid - 1;  
			else
				lo = mid;
		}		
		b=lo;
		cout<<"Case "<<e++<<": "<<b-a+1<<endl;
	}
	
	
	return 0;

}